#ifndef OUTSTATION_H
#define OUTSTATION_H

#include <QThread>

#include <asiodnp3/DNP3Manager.h>
#include <asiodnp3/PrintingSOEHandler.h>
#include <asiodnp3/PrintingChannelListener.h>
#include <asiodnp3/ConsoleLogger.h>
#include <asiodnp3/UpdateBuilder.h>
#include <asiopal/UTCTimeSource.h>
#include <opendnp3/outstation/SimpleCommandHandler.h>
#include <opendnp3/outstation/IUpdateHandler.h>
#include <opendnp3/LogLevels.h>

class DatabaseConfig;
class UpdateBuilder;
struct State;
struct DeviceData;

class Outstation :public QThread
{

public:
    Outstation(DeviceData *dd = nullptr);
    DeviceData *DD;
    void ConfigureDatabase(asiodnp3::DatabaseConfig& config);
    void AddUpdates(asiodnp3::UpdateBuilder& builder, State& state, const std::string& arguments);
    void run();



private:


};

#endif // OUTSTATION_H
