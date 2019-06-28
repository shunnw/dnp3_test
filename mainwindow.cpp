#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QObject>
#include <iostream>
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include "dnp3_dds.hpp"
#include "ooodds.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    DDS_pub(nullptr),
    DDS_sub(nullptr)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer();
    timer->start(1000);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeDisplay()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeDisplay()
{
    ui->timeLabel->setText("Current Time: "+QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::on_checkBox_mas_clicked()
{
    ui->checkBox_mas->isChecked();
    RUN_master = new Master();
    RUN_master->start();
}

void MainWindow::on_checkBox_out_clicked()
{
    ui->checkBox_out->isChecked();
    data = new DeviceData;
    RUN_modbus = new getmodbus(this, ui->deviceLabel, data);
    RUN_modbus->start();
    RUN_outstation = new Outstation(data);
    RUN_outstation->start();
}



void MainWindow::on_checkBox_pub_stateChanged(int arg1)
{
    if(ui->checkBox_pub->isChecked())
        {

//            // create a DDS if no one exists
            if(this->DDS_pub == nullptr)
                this->DDS_pub = new oooDDS(0 ,Data_pub, DDS_PUB);

//            //connect the label_pub to DDS_pub signal
            connect(this->DDS_pub, SIGNAL(response_pub_sub(QString)), this->ui->label_pub, SLOT(setText(QString)));
            DDS_pub->set_count(100);
            DDS_pub->set_delay(1);
            DDS_pub->set_always(1);
            DDS_pub->start();

        }
        else{
//            // Destroy participants, topic, writer and instance in DDS
            DDS_pub->dds_destroy();

//            //disconnect the label_pub and DDS_pub
            disconnect(this->DDS_pub, SIGNAL(response_pub_sub(QString)), this->ui->label_pub, SLOT(setText(QString)));

//            // Free DDS
            delete this->DDS_pub;
            this->DDS_pub = nullptr;



        }
}

void MainWindow::on_checkBox_sub_stateChanged(int arg1)
{
    if(ui->checkBox_sub->isChecked())
       {
           // create a DDS if no one exists
           if(this->DDS_sub == nullptr)
               this->DDS_sub = new oooDDS(0, &this->Data_sub, DDS_SUB);

           //connect the label_sub to DDS_sub signal
           connect(this->DDS_sub, SIGNAL(response_pub_sub(QString)), this->ui->label_sub, SLOT(setText(QString)));
           DDS_sub->set_count(100);
           DDS_sub->set_delay(1);
           DDS_sub->set_always(1);
           DDS_sub->start();
       }
       else{
           // Destroy participants, topic, writer and instance in DDS
           DDS_sub->dds_destroy();

           //disconnect the label_pub and DDS_sub
           disconnect(this->DDS_sub, SIGNAL(response_pub_sub(QString)), this->ui->label_sub, SLOT(setText(QString)));

           // Free DDS
           delete this->DDS_sub;
           this->DDS_sub = nullptr;

       }
}
