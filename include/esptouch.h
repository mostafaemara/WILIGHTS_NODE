#include <Arduino.h>
#include "smartconfig.h"
#include "user_interface.h"
#include "osapi.h"
#include "ets_sys.h"
#include "eeprom.h"
#include <mem.h>
#include "s_debug.h"
#define ESPTOUCH_INTR_PIN 0

#if defined(ESPTOUCH_DEBUG_ON)
#define ESPTOUCH_INFO(format, ...) Serial.printf(format, ##__VA_ARGS__)
#else
#define ESPTOUCH_INFO(format, ...)
#endif
void esptouch_init(void);
void esptouch_start(void);
bool esptouch_done(void);