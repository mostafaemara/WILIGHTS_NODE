#include "wl_json.h"

String json_creat_node_info_messege(String state)
{
  JSON_INFO("\n JSON: CREATING NODE INFO MESSEGE \n");
  DynamicJsonBuffer jsonBuffer(JSON_BUFFER_SIZE);
  JsonObject &root = jsonBuffer.createObject();
  String json;
  unsigned char r1 = get_relay_state(RELAY_1);
  unsigned char r2 = get_relay_state(RELAY_2);
  unsigned char r3 = get_relay_state(RELAY_3);
  unsigned char r4 = get_relay_state(RELAY_4);
  root[JSON_KEY_MESSEGE_ID] = MESSEGE_ID_NODE_INFO;
  root[JSON_KEY_NODE_ID] = ESP.getChipId();
  root[JSON_KEY_NODE_STATE] = state;
  root[JSON_KEY_RELAY_NUMBER_1] = r1;
  root[JSON_KEY_RELAY_NUMBER_2] = r2;
  root[JSON_KEY_RELAY_NUMBER_3] = r3;
  root[JSON_KEY_RELAY_NUMBER_4] = r4;

  root.prettyPrintTo(json);
  JSON_INFO("\n JSON: CREATING NODE INFO MESSEGE DONE\n JSON = %s\n", json.c_str());
  jsonBuffer.clear();

  return json;
}
int json_extract_messege_id(String json)
{
  DynamicJsonBuffer jsonBuffer(JSON_BUFFER_SIZE);
  JSON_INFO("\n JSON: START EXTRACTING MESSEGE ID FROM \n JSON = %s \n", json.c_str());

  JsonObject &root = jsonBuffer.parseObject(json);

  jsonBuffer.clear();
  if (root.success())
  {

    int messegeid = root[JSON_KEY_MESSEGE_ID];

    JSON_INFO("\n JSON: EXTRACTING MESSEGE ID SUCCES \n MESSEGE ID =%d \n", messegeid);
    return messegeid;
  }
  else
  {
    JSON_INFO("\n JSON: EXTRACTING MESSEGE ID FAILD\n");
    return -1;
  }
}
uint32_t json_extract_node_id(String json)
{
  DynamicJsonBuffer jsonBuffer(JSON_BUFFER_SIZE);

  JSON_INFO("\n JSON: START EXTRACTING NODE ID FROM \n JSON = %s \n", json.c_str());
  JsonObject &root = jsonBuffer.parseObject(json);

  jsonBuffer.clear();
  if (root.success())
  {

    uint32_t nodeid = root[JSON_KEY_NODE_ID];
    JSON_INFO("\n JSON: EXTRACTING NODE ID SUCCES \n NODE ID =%d \n", nodeid);

    return nodeid;
  }
  else
  {
    JSON_INFO("\n JSON: EXTRACTING NODE ID FAILD\n");

    return -1;
  }
}
void json_extract_node_cmd_messege(String json, int *relayno, int *cmd)
{
  DynamicJsonBuffer jsonBuffer(JSON_BUFFER_SIZE);
  JSON_INFO("\n JSON: START EXTRACTING NODE COMMAND MESSGE FROM \n JSON = %s \n", json.c_str());
  JsonObject &root = jsonBuffer.parseObject(json);
  if (root.success())
  {

    *cmd = root[JSON_KEY_COMMAND];
    *relayno = root[JSON_KEY_RELAY_NUMBER];
    JSON_INFO("\n JSON: EXTRACTING NODE COMMAND MESSEGE SUCESS \n COMMAND = %d FOR RELAY Number = %d \n", *cmd, *relayno);
  }
  else
  {
    JSON_INFO("\n JSON: EXTRACTING NODE COMMAND MESSEGE FAILD \n");
    *cmd = -1;
    *relayno = -1;
  }
  JSON_INFO("\n JSON: EXTRACTING NODE COMMAND MESSEGE DONE CLEARING JSON BUFFER \n");
  jsonBuffer.clear();
}