#ifndef GETMODBUS_H
#define GETMODBUS_H

#include <QThread>
#include <QMutex>
#include <QString>
#include <QTimer>
#include <QLabel>
#include <QTime>
#include <QtSerialBus/QModbusDataUnit>
#include <QtSerialBus/QModbusTcpClient>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusDevice>

class QModbusClient;
class QModbusReply;
class QModbusResponse;


union UInt_Int
{
    unsigned short int usint;
    short int sint;
};


struct DeviceData {
    float Current;
    float Voltage;
    float Power;
    float Frequency;
};


class getmodbus :public QThread
{
    Q_OBJECT

public:
    getmodbus(QObject *parent = nullptr, QLabel *deviceLabel = nullptr, DeviceData *dd = nullptr);
    ~getmodbus();
    void run();

public:
    QString portname;
    QString devicename;
    QLabel *deviceLabel;
    void SetCommPara( QString, int, int, int, int, int, int);
    void OpenSerialPort();
    QModbusDataUnit readRequest(int, int, int) const;
    QModbusReply *lastRequest;
    QModbusClient *modbusDevice;
    QTimer *CommTimer;
    DeviceData *DD;
    int deviceid;
    void PrepareReadRequest();

private:
    int baudrate;
    int parity;
    int databit;
    int stopbit;
    int timeout;
    int retry;
    int labelindex;
    int startingAddress;
    int readLength;
    bool mutex=true;
    void msleep(int);


private Q_SLOTS:
    void SendCommRequest();
    //void PrepareReadRequest();
        Q_SIGNALS:
    void StatusUpdate(QString, int, QString);
};

#endif // GETMODBUS_H
