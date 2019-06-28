

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dnp3_dds.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef dnp3_dds_1291549720_hpp
#define dnp3_dds_1291549720_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport dnp3data {

  public:
    dnp3data();

    dnp3data(
        float current,
        float voltage,
        float power,
        float frequency);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    dnp3data (dnp3data&&) = default;
    dnp3data& operator=(dnp3data&&) = default;
    dnp3data& operator=(const dnp3data&) = default;
    dnp3data(const dnp3data&) = default;
    #else
    dnp3data(dnp3data&& other_) OMG_NOEXCEPT;  
    dnp3data& operator=(dnp3data&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    float& current() OMG_NOEXCEPT; 
    const float& current() const OMG_NOEXCEPT;
    void current(float value);

    float& voltage() OMG_NOEXCEPT; 
    const float& voltage() const OMG_NOEXCEPT;
    void voltage(float value);

    float& power() OMG_NOEXCEPT; 
    const float& power() const OMG_NOEXCEPT;
    void power(float value);

    float& frequency() OMG_NOEXCEPT; 
    const float& frequency() const OMG_NOEXCEPT;
    void frequency(float value);

    bool operator == (const dnp3data& other_) const;
    bool operator != (const dnp3data& other_) const;

    void swap(dnp3data& other_) OMG_NOEXCEPT ;

  private:

    float m_current_;
    float m_voltage_;
    float m_power_;
    float m_frequency_;

};

inline void swap(dnp3data& a, dnp3data& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const dnp3data& sample);

namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<dnp3data> {
            NDDSUSERDllExport static std::string value() {
                return "dnp3data";
            }
        };

        template<>
        struct is_topic_type<dnp3data> : public dds::core::true_type {};

        template<>
        struct topic_type_support<dnp3data> {
            NDDSUSERDllExport 
            static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const dnp3data& sample);

            NDDSUSERDllExport 
            static void from_cdr_buffer(dnp3data& sample, const std::vector<char>& buffer);

            NDDSUSERDllExport 
            static void reset_sample(dnp3data& sample);

            NDDSUSERDllExport 
            static void allocate_sample(dnp3data& sample, int, int);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<dnp3data> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility<dnp3data> {
            static const dds::core::xtypes::ExtensibilityKind::type kind =
            dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // dnp3_dds_1291549720_hpp

