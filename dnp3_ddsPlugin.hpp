

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from dnp3_dds.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef dnp3_ddsPlugin_1291549720_h
#define dnp3_ddsPlugin_1291549720_h

#include "dnp3_dds.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define dnp3dataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define dnp3dataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define dnp3dataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define dnp3dataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define dnp3dataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern dnp3data*
dnp3dataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern dnp3data*
dnp3dataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern dnp3data*
dnp3dataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
dnp3dataPluginSupport_copy_data(
    dnp3data *out,
    const dnp3data *in);

NDDSUSERDllExport extern void 
dnp3dataPluginSupport_destroy_data_w_params(
    dnp3data *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
dnp3dataPluginSupport_destroy_data_ex(
    dnp3data *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
dnp3dataPluginSupport_destroy_data(
    dnp3data *sample);

NDDSUSERDllExport extern void 
dnp3dataPluginSupport_print_data(
    const dnp3data *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
dnp3dataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
dnp3dataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
dnp3dataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
dnp3dataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
dnp3dataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data *out,
    const dnp3data *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const dnp3data *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
dnp3dataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const dnp3data *sample); 

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
dnp3dataPlugin_deserialize_from_cdr_buffer(
    dnp3data *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern RTIBool
dnp3dataPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
dnp3dataPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
dnp3dataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
dnp3dataPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
dnp3dataPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const dnp3data * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
dnp3dataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
dnp3dataPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
dnp3dataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const dnp3data *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
dnp3dataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
dnp3dataPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    dnp3data *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
dnp3dataPlugin_new(void);

NDDSUSERDllExport extern void
dnp3dataPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* dnp3_ddsPlugin_1291549720_h */

