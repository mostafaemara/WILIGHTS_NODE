#include"wl_mesh.h"

painlessMesh  mesh;

void receivedCallback(uint32_t from, String & msg);



void receivedCallback(uint32_t from, String & msg) {

  String nodeinfo=json_creat_node_info_messege("connect");
int messegeid=json_extract_messege_id(msg);
int cmd,relayno;

  switch (messegeid)
  {
    case MESSEGE_ID_HANDSHAKE:
   Serial.println("\n Handshake Recived \n ");

mesh.sendSingle(from,nodeinfo);
      break;
  case MESSEGE_ID_COMMAND:

  if(json_extract_node_id(msg)==ESP.getChipId()){


json_extract_node_cmd_messege(msg,&relayno,&cmd);
relay_set(relayno,cmd);
nodeinfo=json_creat_node_info_messege("connect");
mesh.sendSingle(from,nodeinfo);
  }
  break;
    default:
    Serial.println("\n SomthingElse Recived \n ");
  
      break;
  }
  
  
}

void mesh_init(void){
String ssid=eeprom_read_ssid();
String pwd=eeprom_read_password();
 mesh.setDebugMsgTypes(ERROR | DEBUG | CONNECTION);  // set before init() so that you can see startup messages

  mesh.init(ssid, pwd, MESH_PORT,WIFI_AP_STA,6);
  mesh.onReceive(&receivedCallback);
  
 
  mesh.setContainsRoot(true);


}
void mesh_update(void){



     mesh.update();
}