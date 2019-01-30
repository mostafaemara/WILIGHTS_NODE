
#include <painlessMesh.h>
#include"wl_relay_state.h"
#include "wl_utils.h"
#include"wl_debug.h"
#define JSON_KEY_MESSEGE_ID "messegeid"
#define JSON_KEY_NODE_ID "nodeid"
#define JSON_KEY_NODE_STATE "nodestate"
#define JSON_KEY_RELAY_NUMBER_1 "relay1"
#define JSON_KEY_RELAY_NUMBER_2 "relay2"
#define JSON_KEY_RELAY_NUMBER_3 "relay3"
#define JSON_KEY_RELAY_NUMBER_4 "relay4"
#define JSON_KEY_COMMAND "cmd"
#define JSON_KEY_RELAY_NUMBER "relayno"
#define JSON_BUFFER_SIZE 5000

#if defined(JSON_DEBUG_ON)
#define JSON_INFO( format, ... ) Serial.printf( format, ## __VA_ARGS__ )
#else
#define JSON_INFO( format, ... )
#endif

String json_creat_node_info_messege(String state);
int json_extract_messege_id(String json);
void json_extract_node_cmd_messege(String json,int*relayno,int*cmd);
uint32_t json_extract_node_id(String json);