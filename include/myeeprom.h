#include <EEPROM.h>
#include<Arduino.h>
#include"s_debug.h"

#if defined(EEPROM_DEBUG_ON)
#define EEPROM_INFO( format, ... ) Serial.printf( format, ## __VA_ARGS__ )
#else
#define EEPROM_INFO( format, ... )
#endif
void eeprom_init(void);
String eeprom_read_ssid(void);
String eeprom_read_password(void);
void eeprom_write_ssid(String ssid);
void eeprom_write_password(String password);