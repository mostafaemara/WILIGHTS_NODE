//************************************************************
// this is a simple example that uses the easyMesh library
//
// 1. blinks led once for every node on the mesh
// 2. blink cycle repeats every BLINK_PERIOD
// 3. sends a silly message to every node on the mesh at a random time between 1 and 5 seconds
// 4. prints anything it receives to Serial.print
//
//
//************************************************************
#include<wl_relay.h>
#include"wl_mesh.h"
#include<EEPROM.h>
#include"wl_esptouch.h"
#include <Arduino.h>
// some gpio pin that is connected to an LED...
// on my rig, this is 5, change to the right number of your LED.
#define   LED             2       // GPIO number of connected LED, ON ESP-12 IS GPIO2





// Prototypes


 // to control your personal task





// Task to blink the number of nodes


void setup() {
esptouch_init();
  mesh_init();
  Serial.begin(115200);
relay_init();
  pinMode(LED, OUTPUT);
 
     

  //mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  //mesh.setDebugMsgTypes(ERROR | DEBUG | CONNECTION | COMMUNICATION);  // set before init() so that you can see startup messages
 


  

 


}

void loop() {
  // it will run mesh scheduler as well
  if(esptouch_done()){
 mesh_update();
}

}


