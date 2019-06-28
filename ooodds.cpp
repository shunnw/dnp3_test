#include "ooodds.h"

#include <algorithm>
#include <iostream>

#include <QString>
#include <QObject>
#include "dnp3_dds.hpp"
#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp> // for sleep()
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>

oooDDS::oooDDS(int domain, DeviceData *Data, bool pub_sub):
    running(0),
    pub_sub(pub_sub),
    Data(Data),
    dds_participant(new dds::domain::DomainParticipant(domain)),
    dds_topic(new dds::topic::Topic<dnp3data>(*this->dds_participant, "Example Example"))
{
    //this->Data=Data;
    //this->participant = new dds::domain::DomainParticipant(0);
    //this->topic = new dds::topic::Topic<Example>(*this->participant, "Example Example");
    //this->writer = new dds::pub::DataWriter<Example>(dds::pub::Publisher(*this->participant), *this->topic);
}

void oooDDS::dds_write()
{
    dds_publisher = new dds::pub::Publisher(*this->dds_participant);
    dds_writer = new dds::pub::DataWriter<dnp3data>(*this->dds_publisher, *this->dds_topic);
    dds_sample = new dnp3data;

    // Set the second bit to 1
    this->running |= 0x10;
    Q_EMIT response_pub_sub("PUBLISHING");

    while(this->count){
        this->dds_sample->current(this->Data->Current);
        this->dds_sample->voltage(this->Data->Voltage);
        this->dds_sample->frequency(this->Data->Frequency);
        this->dds_sample->power(this->Data->Power);
        this->dds_writer->write(*this->dds_sample);
        this->count -= !this->always;
        msleep(this->delaytime);
        sleep(1);
        std::cout<<"PUBBLISHING METER!!"<<std::endl;
        std::cout<<"Voltage is :"<<this->Data->Voltage<<std::endl;
        //std::cout<<this->dds_sample->voltage()<<std::endl;
        std::cout<<"Current is :"<<this->Data->Current<<std::endl;
        //std::cout<<this->dds_sample->current()<<std::endl;
        std::cout<<"Power is :="<<this->Data->Power<<std::endl;
        //std::cout<<this->dds_sample->power()<<std::endl;
        std::cout<<"Frequency is :"<<this->Data->Frequency<<std::endl<<std::endl;;
        //std::cout<<this->dds_sample->frequency()<<std::endl<<std::endl;
    }


    delete this->dds_sample;
    delete this->dds_writer;
    delete this->dds_publisher;

    Q_EMIT response_pub_sub("NO PUB");
    // Set the second bit to 0
    this->running &= (this->running ^ 0x10);
}

void oooDDS::dds_read()
{
    Q_EMIT response_pub_sub("SUBSCRIBING");
    // Set the first bit to 1
    this->running |= 0x01;

    // Create a DataReader with default Qos (Subscriber created in-line)
    this->dds_subscriber = new dds::sub::Subscriber(*this->dds_participant);
    this->dds_reader = new dds::sub::DataReader<dnp3data> (*this->dds_subscriber, *this->dds_topic);

    dds::sub::DataReader<dnp3data> &reader_1 = *this->dds_reader;
    DeviceData &data_1 = *this->Data;
    bool &always_1 = this->always;

    // Create a ReadCondition for any data on this reader and associate a handler
    int count1 = 0;
    dds::sub::cond::ReadCondition read_condition(
        reader_1,
        dds::sub::status::DataState::any(),
        [&reader_1, &count1, &data_1, &always_1]()
    {
        // Take all samples
        dds::sub::LoanedSamples<dnp3data> samples = reader_1.take();
        for (auto sample : samples){
            if (sample.info().valid()){
                count1 += !always_1;
                std::cout << "SUBCRIBING METER!!" << std::endl;
                data_1.Current = sample.data().current();
                data_1.Voltage = sample.data().voltage();
                data_1.Power = sample.data().power();
                data_1.Frequency = sample.data().frequency();
                std::cout<<"Voltage is :"<<data_1.Voltage<<std::endl;
                std::cout<<"Current is :"<<data_1.Current<<std::endl;
                std::cout<<"Power is :="<<data_1.Power<<std::endl;
                std::cout<<"Frequency is :"<<data_1.Frequency<<std::endl<<std::endl;;
            }
        }
    } // The LoanedSamples destructor returns the loan
    );

    // Create a WaitSet and attach the ReadCondition
    dds::core::cond::WaitSet waitset;
    waitset += read_condition;

    while (count1 < this->count && this->count != 0) {
        // Dispatch will call the handlers associated to the WaitSet conditions
        // when they activate
        std::cout << "send response" << std::endl;
        Q_EMIT response_on_sub(data_1.Current);
        waitset.dispatch(dds::core::Duration(this->delaytime)); // Wait up to 4s each time
    }

    waitset.detach_condition(read_condition);
    read_condition.close();
    //delete &waitset;
    //delete &read_condition;
    delete this->dds_reader;
    delete this->dds_subscriber;
    std::cout << "send response1111" << std::endl;

    Q_EMIT response_pub_sub("NO SUB");
    // Set the first bit to 0
    this->running &= (this->running ^ 0x01);
}

void oooDDS::dds_destroy()
{
    // stop publisher
    while(this->running & 0x10){
        set_count(0);
        set_delay(0);
    }

    // stop subscriber
    while(this->running & 0x01){
        set_count(0);
        set_delay(0);
    }

    delete this->dds_participant;
    delete this->dds_topic;
}
