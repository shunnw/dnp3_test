#ifndef MASTER_H
#define MASTER_H

#include <QThread>

#include <asiodnp3/DNP3Manager.h>
#include <asiodnp3/PrintingSOEHandler.h>
#include <asiodnp3/ConsoleLogger.h>
#include <asiodnp3/DefaultMasterApplication.h>
#include <asiodnp3/PrintingCommandCallback.h>
#include <asiodnp3/PrintingChannelListener.h>
#include <asiopal/UTCTimeSource.h>
#include <opendnp3/LogLevels.h>



class Master :public QThread
{
public:
    Master();
    void run();

};

#endif // MASTER_H
