#include "master.h"

using namespace std;
using namespace openpal;
using namespace asiopal;
using namespace asiodnp3;
using namespace opendnp3;

Master::Master()
{

}

void Master::run()
{
        // Specify what log levels to use. NORMAL is warning and above
        // You can add all the comms logging by uncommenting below
        const uint32_t FILTERS = levels::NORMAL | levels::ALL_APP_COMMS;

        // This is the main point of interaction with the stack
        DNP3Manager manager(1, ConsoleLogger::Create());

        // Connect via a TCPClient socket to a outstation
        auto channel = manager.AddTCPClient("tcpclient", FILTERS, ChannelRetry::Default(), "127.0.0.1", "0.0.0.0", 20000, PrintingChannelListener::Create());

        // The master config object for a master. The default are
        // useable, but understanding the options are important.
        MasterStackConfig stackConfig;

        // you can override application layer settings for the master here
        // in this example, we've change the application layer timeout to 2 seconds
        stackConfig.master.responseTimeout = openpal::TimeDuration::Seconds(2);
        stackConfig.master.disableUnsolOnStartup = true;

        // You can override the default link layer settings here
        // in this example we've changed the default link layer addressing
        stackConfig.link.LocalAddr = 1;
        stackConfig.link.RemoteAddr = 10;

        // Create a new master on a previously declared port, with a
        // name, log level, command acceptor, and config info. This
        // returns a thread-safe interface used for sending commands.
        auto master = channel->AddMaster(
                          "master",											// id for logging
                          PrintingSOEHandler::Create(),						// callback for data processing
                          asiodnp3::DefaultMasterApplication::Create(),		// master application instance
                          stackConfig										// stack configuration
                      );

        cout<<"print data"<<endl;
        // do an integrity poll (Class 3/2/1/0) once per minute
        auto integrityScan = master->AddClassScan(ClassField::AllClasses(), openpal::TimeDuration::Minutes(1));

        // do a Class 1 exception poll every 5 seconds
        auto exceptionScan = master->AddClassScan(ClassField(ClassField::CLASS_1), openpal::TimeDuration::Seconds(2));

        // Enable the master. This will start communications.
        master->Enable();

//        bool channelCommsLoggingEnabled = true;
//        bool masterCommsLoggingEnabled = true;

        while (true)
        {
            sleep(1);

//            char cmd;
//            std::cin >> cmd;
//            switch(cmd)
//            {
//            case('a') :
//                master->ScanRange(GroupVariationID(1, 2), 0, 3);
//                break;
//            case('d') :
//                master->PerformFunction("disable unsol", FunctionCode::DISABLE_UNSOLICITED,
//                { Header::AllObjects(60, 2), Header::AllObjects(60, 3), Header::AllObjects(60, 4) }
//                                       );
//                break;
//            case('r') :
//                {
//                    auto print = [](const RestartOperationResult & result)
//                    {
//                        if(result.summary == TaskCompletion::SUCCESS)
//                        {
//                            std::cout << "Success, Time: " << result.restartTime.GetMilliseconds() << std::endl;
//                        }
//                        else
//                        {
//                            std::cout << "Failure: " << TaskCompletionToString(result.summary) << std::endl;
//                        }
//                    };
//                    master->Restart(RestartType::COLD, print);
//                    break;
//                }
//            case('x'):
//                // C++ destructor on DNP3Manager cleans everything up for you
//                //return 0;
//            case('i'):
//                integrityScan->Demand();
//                break;
//            case('e'):
//                exceptionScan->Demand();
//                break;
//            case('c'):
//                {
//                    ControlRelayOutputBlock crob(ControlCode::LATCH_ON);
//                    master->SelectAndOperate(crob, 0, PrintingCommandCallback::Get());
//                    break;
//                }
//            case('t') :
//                {
//                    channelCommsLoggingEnabled = !channelCommsLoggingEnabled;
//                    auto levels = channelCommsLoggingEnabled ? levels::ALL_COMMS : levels::NORMAL;
//                    channel->SetLogFilters(levels);
//                    std::cout << "Channel logging set to: " << levels << std::endl;
//                    break;
//                }
//            case('u') :
//                {
//                    masterCommsLoggingEnabled = !masterCommsLoggingEnabled;
//                    auto levels = masterCommsLoggingEnabled ? levels::ALL_COMMS : levels::NORMAL;
//                    master->SetLogFilters(levels);
//                    std::cout << "Master logging set to: " << levels << std::endl;
//                    break;
//                }
//            default:
//                std::cout << "Unknown action: " << cmd << std::endl;
//                break;
//            }
        }

}
