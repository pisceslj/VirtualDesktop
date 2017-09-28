#include "messages.h"
#include "marshallers.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <spice/protocol.h>
#include <spice/macros.h>
#include <marshaller.h>

#ifdef _MSC_VER
#pragma warning(disable:4101)
#pragma warning(disable:4018)
#endif

static void spice_marshall_msgc_ack_sync(SpiceMarshaller *m, SpiceMsgcAckSync *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcAckSync *src;
    src = (SpiceMsgcAckSync *)msg;

    spice_marshaller_add_uint32(m, src->generation);
}

static void spice_marshall_SpiceMsgEmpty(SpiceMarshaller *m, SpiceMsgEmpty *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgEmpty *src;
    src = (SpiceMsgEmpty *)msg;

}

static void spice_marshall_msgc_pong(SpiceMarshaller *m, SpiceMsgPing *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgPing *src;
    src = (SpiceMsgPing *)msg;

    spice_marshaller_add_uint32(m, src->id);
    spice_marshaller_add_uint64(m, src->timestamp);
}

static void spice_marshall_SpiceMsgData(SpiceMarshaller *m, SpiceMsgData *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgData *src;
    src = (SpiceMsgData *)msg;

    /* Remaining data must be appended manually */
}

static void spice_marshall_msgc_disconnecting(SpiceMarshaller *m, SpiceMsgDisconnect *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgDisconnect *src;
    src = (SpiceMsgDisconnect *)msg;

    spice_marshaller_add_uint64(m, src->time_stamp);
    spice_marshaller_add_uint32(m, src->reason);
}

static void spice_marshall_msgc_main_client_info(SpiceMarshaller *m, SpiceMsgcClientInfo *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcClientInfo *src;
    src = (SpiceMsgcClientInfo *)msg;

    spice_marshaller_add_uint64(m, src->cache_size);
}

static void spice_marshall_msgc_main_mouse_mode_request(SpiceMarshaller *m, SpiceMsgcMainMouseModeRequest *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMainMouseModeRequest *src;
    src = (SpiceMsgcMainMouseModeRequest *)msg;

    spice_marshaller_add_uint32(m, src->mode);
}

static void spice_marshall_msgc_main_agent_start(SpiceMarshaller *m, SpiceMsgcMainAgentStart *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMainAgentStart *src;
    src = (SpiceMsgcMainAgentStart *)msg;

    spice_marshaller_add_uint32(m, src->num_tokens);
}

static void spice_marshall_msgc_main_agent_token(SpiceMarshaller *m, SpiceMsgcMainAgentTokens *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMainAgentTokens *src;
    src = (SpiceMsgcMainAgentTokens *)msg;

    spice_marshaller_add_uint32(m, src->num_tokens);
}

static void spice_marshall_msgc_display_init(SpiceMarshaller *m, SpiceMsgcDisplayInit *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcDisplayInit *src;
    src = (SpiceMsgcDisplayInit *)msg;

    spice_marshaller_add_uint8(m, src->pixmap_cache_id);
    spice_marshaller_add_int64(m, src->pixmap_cache_size);
    spice_marshaller_add_uint8(m, src->glz_dictionary_id);
    spice_marshaller_add_int32(m, src->glz_dictionary_window_size);
}

static void spice_marshall_msgc_inputs_key_down(SpiceMarshaller *m, SpiceMsgcKeyDown *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcKeyDown *src;
    src = (SpiceMsgcKeyDown *)msg;

    spice_marshaller_add_uint32(m, src->code);
}

static void spice_marshall_msgc_inputs_key_up(SpiceMarshaller *m, SpiceMsgcKeyUp *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcKeyUp *src;
    src = (SpiceMsgcKeyUp *)msg;

    spice_marshaller_add_uint32(m, src->code);
}

static void spice_marshall_msgc_inputs_key_modifiers(SpiceMarshaller *m, SpiceMsgcKeyModifiers *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcKeyModifiers *src;
    src = (SpiceMsgcKeyModifiers *)msg;

    spice_marshaller_add_uint32(m, src->modifiers);
}

static void spice_marshall_msgc_inputs_mouse_motion(SpiceMarshaller *m, SpiceMsgcMouseMotion *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMouseMotion *src;
    src = (SpiceMsgcMouseMotion *)msg;

    spice_marshaller_add_int32(m, src->dx);
    spice_marshaller_add_int32(m, src->dy);
    spice_marshaller_add_uint32(m, src->buttons_state);
}

static void spice_marshall_msgc_inputs_mouse_position(SpiceMarshaller *m, SpiceMsgcMousePosition *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMousePosition *src;
    src = (SpiceMsgcMousePosition *)msg;

    spice_marshaller_add_uint32(m, src->x);
    spice_marshaller_add_uint32(m, src->y);
    spice_marshaller_add_uint32(m, src->buttons_state);
    spice_marshaller_add_uint8(m, src->display_id);
}

static void spice_marshall_msgc_inputs_mouse_press(SpiceMarshaller *m, SpiceMsgcMousePress *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMousePress *src;
    src = (SpiceMsgcMousePress *)msg;

    spice_marshaller_add_uint32(m, src->button);
    spice_marshaller_add_uint32(m, src->buttons_state);
}

static void spice_marshall_msgc_inputs_mouse_release(SpiceMarshaller *m, SpiceMsgcMouseRelease *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcMouseRelease *src;
    src = (SpiceMsgcMouseRelease *)msg;

    spice_marshaller_add_uint32(m, src->button);
    spice_marshaller_add_uint32(m, src->buttons_state);
}

static void spice_marshall_msgc_record_data(SpiceMarshaller *m, SpiceMsgcRecordPacket *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcRecordPacket *src;
    src = (SpiceMsgcRecordPacket *)msg;

    spice_marshaller_add_uint32(m, src->time);
    /* Don't marshall @nomarshal data */
}

static void spice_marshall_msgc_record_mode(SpiceMarshaller *m, SpiceMsgcRecordMode *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcRecordMode *src;
    src = (SpiceMsgcRecordMode *)msg;

    spice_marshaller_add_uint32(m, src->time);
    spice_marshaller_add_uint32(m, src->mode);
    /* Remaining data must be appended manually */
}

static void spice_marshall_msgc_record_start_mark(SpiceMarshaller *m, SpiceMsgcRecordStartMark *msg)
{
    SPICE_GNUC_UNUSED SpiceMarshaller *m2;
    SpiceMsgcRecordStartMark *src;
    src = (SpiceMsgcRecordStartMark *)msg;

    spice_marshaller_add_uint32(m, src->time);
}

SpiceMessageMarshallers * spice_message_marshallers_get1(void)
{
    static SpiceMessageMarshallers marshallers = {NULL};

    marshallers.msg_SpiceMsgData = spice_marshall_SpiceMsgData;
    marshallers.msg_SpiceMsgEmpty = spice_marshall_SpiceMsgEmpty;
    marshallers.msgc_ack_sync = spice_marshall_msgc_ack_sync;
    marshallers.msgc_disconnecting = spice_marshall_msgc_disconnecting;
    marshallers.msgc_display_init = spice_marshall_msgc_display_init;
    marshallers.msgc_inputs_key_down = spice_marshall_msgc_inputs_key_down;
    marshallers.msgc_inputs_key_modifiers = spice_marshall_msgc_inputs_key_modifiers;
    marshallers.msgc_inputs_key_up = spice_marshall_msgc_inputs_key_up;
    marshallers.msgc_inputs_mouse_motion = spice_marshall_msgc_inputs_mouse_motion;
    marshallers.msgc_inputs_mouse_position = spice_marshall_msgc_inputs_mouse_position;
    marshallers.msgc_inputs_mouse_press = spice_marshall_msgc_inputs_mouse_press;
    marshallers.msgc_inputs_mouse_release = spice_marshall_msgc_inputs_mouse_release;
    marshallers.msgc_main_agent_start = spice_marshall_msgc_main_agent_start;
    marshallers.msgc_main_agent_token = spice_marshall_msgc_main_agent_token;
    marshallers.msgc_main_client_info = spice_marshall_msgc_main_client_info;
    marshallers.msgc_main_mouse_mode_request = spice_marshall_msgc_main_mouse_mode_request;
    marshallers.msgc_pong = spice_marshall_msgc_pong;
    marshallers.msgc_record_data = spice_marshall_msgc_record_data;
    marshallers.msgc_record_mode = spice_marshall_msgc_record_mode;
    marshallers.msgc_record_start_mark = spice_marshall_msgc_record_start_mark;

    return &marshallers;
}

