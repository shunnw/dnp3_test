#include "outstation.h"
#include "getmodbus.h"
#include <string.h>
#include <string>
#include <thread>
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace opendnp3;
using namespace openpal;
using namespace asiopal;
using namespace asiodnp3;

Outstation::Outstation(DeviceData* dd)
{
    this->DD=dd;
}
struct State
{
    uint32_t count = 0;
    double value = 0;
    bool binary = false;
    DoubleBit dbit = DoubleBit::DETERMINED_OFF;
    uint8_t octetStringValue = 1;
};

void Outstation::ConfigureDatabase(asiodnp3::DatabaseConfig& config)
{
        // example of configuring analog index 0 for Class2 with floating point variations by default
        config.analog[0].clazz = PointClass::Class2;
        config.analog[0].svariation = StaticAnalogVariation::Group30Var5;
        config.analog[0].evariation = EventAnalogVariation::Group32Var7;
}
void AddUpdates(asiodnp3::UpdateBuilder& builder, State& state, const std::string& arguments);
void Outstation::run()
{
    // Specify whvoid Outstation::AddUpdatesat log levels to use. NORMAL is warning and above
        // You can add all the comms logging by uncommenting below.
        const uint32_t FILTERS = levels::NORMAL | levels::ALL_COMMS;

        // This is the main point of interaction with the stack
        // Allocate a single thread to the pool since this is a single outstation
        // Log messages to the console
        DNP3Manager manager(1, ConsoleLogger::Create());

        // Create a TCP server (listener)
        auto channel = manager.AddTCPServer("server", FILTERS, ServerAcceptMode::CloseExisting, "0.0.0.0", 20000, PrintingChannelListener::Create());

        // The main object for a outstation. The defaults are useable,
        // but understanding the options are important.
        OutstationStackConfig config(DatabaseSizes::AllTypes(10));

        // Specify the maximum size of the event buffers
        config.outstation.eventBufferConfig = EventBufferConfig::AllTypes(10);

        // you can override an default outstation parameters here
        // in this example, we've enabled the oustation to use unsolicted reporting
        // if the master enables it
        config.outstation.params.allowUnsolicited = true;

        // You can override the default link layer settings here
        // in this example we've changed the default link layer addressing
        config.link.LocalAddr = 10;
        config.link.RemoteAddr = 1;

        config.link.KeepAliveTimeout = openpal::TimeDuration::Max();

        // You can optionally change the default reporting variations or class assignment prior to enabling the outstation
        ConfigureDatabase(config.dbConfig);

        // Create a new outstation with a log level, command handler, and
        // config info this	returns a thread-safe interface used for
        // updating the outstation's database.
        auto outstation = channel->AddOutstation("outstation", SuccessCommandHandler::Create(), DefaultOutstationApplication::Create(), config);

        // Enable the outstation and start communications
        outstation->Enable();

        // variables used in example loop
        string input;
        State state;


        while (true)
        {
            sleep(1);
            if (input == "quit") return; // DNP3Manager destructor cleanups up everything automatically
            else
            {
                // update measurement values based on input string
                asiodnp3::UpdateBuilder builder;
                AddUpdates(builder, state, input);
                outstation->Apply(builder.Build());
                cout<<"READ METER!!"<<endl;
                cout<<"Voltage is :"<<DD->Voltage<<" V"<<endl;
                cout<<"Current is :"<<DD->Current<<" A"<<endl;
                cout<<"Power is :"<<DD->Power<<" W"<<endl;
                cout<<"Frequency is :"<<DD->Frequency<<" Hz"<<endl<<endl;
            }
        }

}

void Outstation::AddUpdates(asiodnp3::UpdateBuilder& builder, State& state, const std::string& arguments)
{
    for (const char& c : arguments)
    {
        switch (c)
        {
        case('c'):
            {
                builder.Update(Counter(state.count), 0);
                ++state.count;
                break;
            }
        case('a'):
            {
                builder.Update(Analog(state.value), 0);
                state.value += 1;
                break;
            }
        case('b'):
            {
                builder.Update(Binary(state.binary), 0);
                state.binary = !state.binary;
                break;
            }
        case('d'):
            {
                builder.Update(DoubleBitBinary(state.dbit), 0);
                state.dbit = (state.dbit == DoubleBit::DETERMINED_OFF) ? DoubleBit::DETERMINED_ON : DoubleBit::DETERMINED_OFF;
                break;
            }
        case('o'):
            {
                OctetString value(openpal::RSlice(&state.octetStringValue, 1));
                builder.Update(value, 0);
                state.octetStringValue += 1;
                break;
            }
        default:
            break;
        }
    }
}
