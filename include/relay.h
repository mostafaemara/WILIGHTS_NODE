#include<Arduino.h>
#include"utils.h"
#include"relaystate.h"
#define RELAY_1_PIN  14
#define RELAY_2_PIN  12
#define RELAY_3_PIN  13
#define RELAY_4_PIN  15
#define ON LOW
#define OFF HIGH
void relay_init(void);
void relay_set(u8 relayno,u8 cmd);
