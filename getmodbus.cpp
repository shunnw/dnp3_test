#include "getmodbus.h"
#include <QtWidgets>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>

using namespace std;

getmodbus::getmodbus(QObject *parent,QLabel *deviceLabel, DeviceData* dd): QThread(parent)
{
    devicename = "Meter";
    deviceid = 1;
    portname = "/dev/ttyUSB0";
    baudrate = QSerialPort::Baud19200;
    parity = QSerialPort::NoParity;
    databit= QSerialPort::Data8;
    stopbit= QSerialPort::OneStop;
    timeout = 200;
    retry = 0;
    this->deviceLabel=deviceLabel;

    this->DD=dd;
    DD->Current = 0;
    DD->Voltage = 0;
    DD->Power = 0;
    DD->Frequency = 0;

}

void getmodbus::run()
{
    cout<<devicename.toStdString()<<" is activated."<<endl;
    deviceLabel->setText(devicename+" is activated.");

    modbusDevice = new QModbusRtuSerialMaster();
    SetCommPara(portname,baudrate,parity,databit,stopbit,timeout,retry);
    OpenSerialPort();

    while(true)
    {
        sleep(1);
//        CommTimer = new QTimer(this);
//        CommTimer->start(1000); //以1000毫秒為周期起動定時器
//        connect(CommTimer,SIGNAL(timeout()),this,SLOT(PrepareReadRequest()));
        PrepareReadRequest();
    }
}

void getmodbus::OpenSerialPort()
{
    modbusDevice->connectDevice();
    modbusDevice->disconnectDevice();
    //QTime time = QTime::currentTime();
        if (modbusDevice->connectDevice())
        {
            if(modbusDevice->state()== QModbusDevice::ConnectedState)
            {
                deviceLabel->setText(portname+ " Open Successfully");
                cout<<portname.toStdString()<<" Open Successfully"<<endl;
            }
        }
        else
        {
            deviceLabel->setText(portname + " Connection: "+modbusDevice->errorString());
            cout<<portname.toStdString()<<" Connection: "<<modbusDevice->errorString().toStdString()<<endl;
            DD->Voltage = -1;
            DD->Current = -1;
            DD->Power = -1;
            DD->Frequency = -1;
            deviceLabel->setText("Meter "+ QString::number(deviceid)+" : "+modbusDevice->errorString()+"\n"+
                                  "Voltage: "+QString::number(static_cast<double>(DD->Voltage))+ " V"+ "\n"+
                                  "Current: "+QString::number(static_cast<double>(DD->Current))+ " A"+ "\n"+
                                  "Power: "+QString::number(static_cast<double>(DD->Power))+ " W"+ "\n"+
                                  "Frequency: "+QString::number(static_cast<double>(DD->Frequency))+ " Hz");
//            cout<<"Voltage is :"<<DD->Voltage<<" V"<<endl;
//            cout<<"Current is :"<<DD->Current<<" A"<<endl;
//            cout<<"Power is :"<<DD->Power<<" W"<<endl;
//            cout<<"Frequency is :"<<DD->Frequency<<" Hz"<<endl;
            modbusDevice->disconnectDevice();
        }
}

void getmodbus::SendCommRequest()
{
    QTime time = QTime::currentTime();
    if(time.second()%10==0)
    {
        deviceLabel->setText(time.toString("hh:mm:ss")+" send request every 10 second ");
        cout<<" send request every 10 second "<<endl;
    }
}

void getmodbus::PrepareReadRequest()
{
    mutex=false;
    if (!modbusDevice)
        return;
    QTime time = QTime::currentTime();
    if(devicename=="Meter")
    {
            //cout<<"Read Meter"<<endl;
            startingAddress=20;
            readLength=27;
    }
    if (!modbusDevice)
    {
        cout<<"not device"<<endl;
        return;
    }

    if(auto *reply = modbusDevice->sendReadRequest(readRequest(QModbusDataUnit::HoldingRegisters, 20, 27), deviceid))
    {
        while(!reply->isFinished())
            QEventLoop().processEvents(QEventLoop::ExcludeUserInputEvents, modbusDevice->timeout());
        if (!reply)
            return;
        if (reply->error() == QModbusDevice::NoError)
        {  //normal response
            //cout<<"READ METER!!"<<endl;
            const QModbusDataUnit unit = reply->result();
            DD->Voltage = unit.value(0)*0.1f;
            DD->Current = unit.value(6)*0.1f;
            DD->Power = unit.value(10)*0.1f;
            DD->Frequency = unit.value(26)*0.1f;
//            cout<<"Voltage is :"<<DD->Voltage<<" V"<<endl;
//            cout<<"Current is :"<<DD->Current*4/100<<" A"<<endl;
//            cout<<"Power is :"<<DD->Power*4<<" W"<<endl;
//            cout<<"Frequency is :"<<DD->Frequency/10<<" Hz"<<endl;
            deviceLabel->setText("Meter "+ QString::number(deviceid)+"  :"+time.toString("hh:mm:ss")+"\n"+
                                  "Voltage: "+QString::number(static_cast<double>(DD->Voltage))+ " V"+ "\n"+
                                  "Current: "+QString::number(static_cast<double>(DD->Current*4/100))+ " A"+ "\n"+
                                  "Power: "+QString::number(static_cast<double>(DD->Power*4))+ " W"+ "\n"+
                                  "Frequency: "+QString::number(static_cast<double>(DD->Frequency/10))+ " Hz");
        }
        else  //response error
        {
            DD->Voltage=-1;
            deviceLabel->setText(time.toString("hh:mm:ss")+"\n"+"Meter response error:" + modbusDevice->errorString());
            cout<<modbusDevice->errorString().toStdString()<<endl;
        }
    }
}

QModbusDataUnit getmodbus::readRequest(int funcCode, int startAddress, int numberOfEntries) const
{
    const auto table = static_cast<QModbusDataUnit::RegisterType> (funcCode);
    return QModbusDataUnit(table, startAddress, static_cast<quint16>(numberOfEntries));
}

void getmodbus::SetCommPara( QString portName, int baudrate, int parity, int databit, int stopbit, int timeout, int retry)
{
    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter, portName);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter, parity);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, baudrate);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, databit);
    modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, stopbit);
    modbusDevice->setTimeout(timeout);
    modbusDevice->setNumberOfRetries(retry);
}



getmodbus::~getmodbus()
{
    if (modbusDevice->state()== QModbusDevice::ConnectedState)
    {
        CommTimer->stop();
        CommTimer->deleteLater();
        while  (!mutex)
           msleep(1500);
        modbusDevice->disconnectDevice();

    }
    modbusDevice->deleteLater();
}

void getmodbus::msleep(int msec)
{
    QEventLoop loop;

    QTimer::singleShot(msec, &loop, &QEventLoop::quit);

    loop.exec();
}
