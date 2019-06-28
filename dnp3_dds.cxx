

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dnp3_dds.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "dnp3_dds.hpp"
#include "dnp3_ddsPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- dnp3data: 

dnp3data::dnp3data() :
    m_current_ (0.0f) ,
    m_voltage_ (0.0f) ,
    m_power_ (0.0f) ,
    m_frequency_ (0.0f)  {
}   

dnp3data::dnp3data (
    float current,
    float voltage,
    float power,
    float frequency)
    :
        m_current_( current ),
        m_voltage_( voltage ),
        m_power_( power ),
        m_frequency_( frequency ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
dnp3data::dnp3data(dnp3data&& other_) OMG_NOEXCEPT  :m_current_ (std::move(other_.m_current_))
,
m_voltage_ (std::move(other_.m_voltage_))
,
m_power_ (std::move(other_.m_power_))
,
m_frequency_ (std::move(other_.m_frequency_))
{
} 

dnp3data& dnp3data::operator=(dnp3data&&  other_) OMG_NOEXCEPT {
    dnp3data tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void dnp3data::swap(dnp3data& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_current_, other_.m_current_);
    swap(m_voltage_, other_.m_voltage_);
    swap(m_power_, other_.m_power_);
    swap(m_frequency_, other_.m_frequency_);
}  

bool dnp3data::operator == (const dnp3data& other_) const {
    if (m_current_ != other_.m_current_) {
        return false;
    }
    if (m_voltage_ != other_.m_voltage_) {
        return false;
    }
    if (m_power_ != other_.m_power_) {
        return false;
    }
    if (m_frequency_ != other_.m_frequency_) {
        return false;
    }
    return true;
}
bool dnp3data::operator != (const dnp3data& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
float& dnp3data::current() OMG_NOEXCEPT {
    return m_current_;
}

const float& dnp3data::current() const OMG_NOEXCEPT {
    return m_current_;
}

void dnp3data::current(float value) {
    m_current_ = value;
}

float& dnp3data::voltage() OMG_NOEXCEPT {
    return m_voltage_;
}

const float& dnp3data::voltage() const OMG_NOEXCEPT {
    return m_voltage_;
}

void dnp3data::voltage(float value) {
    m_voltage_ = value;
}

float& dnp3data::power() OMG_NOEXCEPT {
    return m_power_;
}

const float& dnp3data::power() const OMG_NOEXCEPT {
    return m_power_;
}

void dnp3data::power(float value) {
    m_power_ = value;
}

float& dnp3data::frequency() OMG_NOEXCEPT {
    return m_frequency_;
}

const float& dnp3data::frequency() const OMG_NOEXCEPT {
    return m_frequency_;
}

void dnp3data::frequency(float value) {
    m_frequency_ = value;
}

std::ostream& operator << (std::ostream& o,const dnp3data& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "current: " << std::setprecision(9) <<sample.current()<<", ";
    o << "voltage: " << std::setprecision(9) <<sample.voltage()<<", ";
    o << "power: " << std::setprecision(9) <<sample.power()<<", ";
    o << "frequency: " << std::setprecision(9) <<sample.frequency() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<dnp3data> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member dnp3data_g_tc_members[4]=
                {

                    {
                        (char *)"current",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"voltage",/* Member name */
                        {
                            1,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"power",/* Member name */
                        {
                            2,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }, 
                    {
                        (char *)"frequency",/* Member name */
                        {
                            3,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode dnp3data_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"dnp3data", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        4, /* Number of members */
                        dnp3data_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for dnp3data*/

                if (is_initialized) {
                    return &dnp3data_g_tc;
                }

                dnp3data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                dnp3data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                dnp3data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                dnp3data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

                is_initialized = RTI_TRUE;

                return &dnp3data_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<dnp3data>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<dnp3data>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<dnp3data>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                dnp3dataPlugin_new,
                dnp3dataPlugin_delete);
        }

        std::vector<char>& topic_type_support<dnp3data>::to_cdr_buffer(
            std::vector<char>& buffer, const dnp3data& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = dnp3dataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = dnp3dataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<dnp3data>::from_cdr_buffer(dnp3data& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = dnp3dataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create dnp3data from cdr buffer");
        }

        void topic_type_support<dnp3data>::reset_sample(dnp3data& sample) 
        {
            rti::topic::reset_sample(sample.current());
            rti::topic::reset_sample(sample.voltage());
            rti::topic::reset_sample(sample.power());
            rti::topic::reset_sample(sample.frequency());
        }

        void topic_type_support<dnp3data>::allocate_sample(dnp3data& sample, int, int) 
        {
        }

    }
}  

