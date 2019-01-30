#include "wl_esptouch.h"
static bool esptouchdone = true;


void handler(void){
 
  byte state = LOW;
 state=!state;
   esptouch_start();

  }
void ICACHE_FLASH_ATTR smartconfig_done(sc_status status, void *pdata)
{

    if (status == SC_STATUS_WAIT)
    {
         ESPTOUCH_INFO("\n ESPTOUCH: WAITING..\n");
    }
    else if (status == SC_STATUS_FIND_CHANNEL)
    {
        ESPTOUCH_INFO("\n ESPTOUCH: FOUND CHANNEL \n");
    }
    else if (status == SC_STATUS_GETTING_SSID_PSWD)
    {
           ESPTOUCH_INFO("\n ESPTOUCH: GETTING SSID & PASSWORD \n");

        sc_type *type = reinterpret_cast<sc_type *>(pdata);
        if (*type == SC_TYPE_ESPTOUCH)
        {
        }
        else
        {
        }
    }
    else if (status == SC_STATUS_LINK)
    {

        struct station_config *sta_conf = reinterpret_cast<station_config *>(pdata);

        ESPTOUCH_INFO("\n ESPTOUCH: GOT SSID & PASSWORD \n");
        ESPTOUCH_INFO("\n ESPTOUCH: SSID %s \n", sta_conf->ssid);
        ESPTOUCH_INFO("\n ESPTOUCH: PASSWORD %s \n", sta_conf->password);

        char *ssid = (char *)sta_conf->ssid;
        char *password = (char *)sta_conf->password;

        // String password=sta_conf->ssid;
        eeprom_write_ssid(ssid);
        eeprom_write_password(password);
        esptouchdone = true;
        ESPTOUCH_INFO("\n ESPTOUCH: RESTARTING \n");
        ESP.restart();
    }
    else if (status == SC_STATUS_LINK_OVER)
    {
        ESPTOUCH_INFO("\n ESPTOUCH: FINISHED & STOPPED \n");
        esptouchdone = true;
        smartconfig_stop();
    }
}
void esptouch_init(void){
 pinMode(ESPTOUCH_INTR_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ESPTOUCH_INTR_PIN), handler, CHANGE);


}
void esptouch_start(void)
{
    ESPTOUCH_INFO("\n ESPTOUCH: ESPTOUCH STARTED \n");
    esptouchdone = false;
     
     wifi_station_disconnect();
wifi_set_opmode(STATION_MODE);

    smartconfig_start(smartconfig_done);
}
bool esptouch_done(void)
{

    return esptouchdone;
}