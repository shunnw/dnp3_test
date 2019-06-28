#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QObject>
#include "master.h"
#include "outstation.h"
#include "getmodbus.h"
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include "dnp3_dds.hpp"
#include "ooodds.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Master *RUN_master;
    Outstation *RUN_outstation;
    getmodbus *RUN_modbus;

public:
    QLabel *timeLabel;
    QLabel *label_pub;
    QLabel *label_sub;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTime *time;
    DeviceData *data;


private Q_SLOTS:
    void on_checkBox_mas_clicked();
    void on_checkBox_out_clicked();
    void onTimeDisplay();
    void on_checkBox_pub_stateChanged(int arg1);
    void on_checkBox_sub_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    DeviceData *Data_pub;
    DeviceData Data_sub;
    oooDDS *DDS_pub;
    oooDDS *DDS_sub;

};

#endif // MAINWINDOW_H
