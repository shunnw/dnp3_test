#ifndef OOODDS_H
#define OOODDS_H

#include <QThread>
#include <QString>
#include <QObject>
#include "dnp3_dds.hpp"
#include "getmodbus.h"
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>

enum PUB_SUB{
    DDS_SUB,
    DDS_PUB
};

class oooDDS: public QThread
{
    Q_OBJECT
public:
    explicit oooDDS(int domain, DeviceData *Data, bool pub_sub);
    //oooDDS(int domain, DeviceData *Data, bool pub_sub);
    void set_count(int n){ this->count = std::abs(n);}
    void set_delay(int t){ this->delaytime = std::abs(t);}
    void set_always(bool n){ this->always = n;}
    void dds_write();
    void dds_read();
    void dds_destroy();
    void run () {
        if(pub_sub)
            this->dds_write();
        else
            this->dds_read();
    }


private:
    int count;
    int running;
    bool always;
    bool pub_sub;
    unsigned long delaytime;
    DeviceData *Data;
    dds::domain::DomainParticipant *dds_participant;
    dds::topic::Topic<dnp3data> *dds_topic;
    dds::pub::Publisher *dds_publisher;
    dds::sub::Subscriber *dds_subscriber;
    dds::pub::DataWriter<dnp3data> *dds_writer;
    dds::sub::DataReader<dnp3data> *dds_reader;
    dnp3data *dds_sample;

 Q_SIGNALS:
    void response_pub_sub(QString);
    void response_on_sub(int);
};

#endif // OOODDS_H
