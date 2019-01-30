#include "relay.h"

void relay_init(void)
{

    pinMode(RELAY_1_PIN, OUTPUT);
    pinMode(RELAY_2_PIN, OUTPUT);
    pinMode(RELAY_3_PIN, OUTPUT);
    pinMode(RELAY_4_PIN, OUTPUT);
unsigned char r1= get_relay_state(RELAY_1);
unsigned char r2= get_relay_state(RELAY_2);
unsigned char r3= get_relay_state(RELAY_3);
unsigned char r4= get_relay_state(RELAY_4);
relay_set(RELAY_1,r1);
relay_set(RELAY_2,r2);
relay_set(RELAY_3,r3);
relay_set(RELAY_4,r4);
}
void relay_set(u8 relayno, u8 cmd)
{

    switch (relayno)
    {
    case RELAY_1:
        if (cmd == RELAY_ON)
        {
            digitalWrite(RELAY_1_PIN, ON);
            save_relay_state(relayno,cmd);
        }
        else if (cmd == RELAY_OFF)
        {
            digitalWrite(RELAY_1_PIN, OFF);
             save_relay_state(relayno,cmd);
        }
        else
        {

            Serial.printf("\n RELAY : ERROR Invalid Command FOR RELAY=%d , COMMAND= %d \n", relayno, cmd);
        }

        break;
    case RELAY_2:
        if (cmd == RELAY_ON)
        {
            digitalWrite(RELAY_2_PIN, ON);
            save_relay_state(relayno,cmd);
        }
        else if (cmd ==RELAY_OFF)
        {
            digitalWrite(RELAY_2_PIN, OFF);
            save_relay_state(relayno,cmd);
        }
        else
        {

            Serial.printf("\n RELAY : ERROR Invalid Command FOR RELAY=%d , COMMAND= %d \n", relayno, cmd);
        }

        break;

    case RELAY_3:
        if (cmd == RELAY_ON)
        {
            digitalWrite(RELAY_3_PIN, ON);
            save_relay_state(relayno,cmd);
        }
        else if (cmd == RELAY_OFF)
        {
            digitalWrite(RELAY_3_PIN, OFF);
            save_relay_state(relayno,cmd);
        }
        else
        {

            Serial.printf("\n RELAY : ERROR Invalid Command FOR RELAY=%d , COMMAND= %d \n", relayno, cmd);
        }

        break;

    case RELAY_4:
        if (cmd == RELAY_ON)
        {
            digitalWrite(RELAY_4_PIN, ON);
            save_relay_state(relayno,cmd);
        }
        else if (cmd == RELAY_OFF)
        {
            digitalWrite(RELAY_4_PIN, OFF);
            save_relay_state(relayno,cmd);
        }
        else
        {

            Serial.printf("\n RELAY : ERROR Invalid Command FOR RELAY=%d , COMMAND= %d \n", relayno, cmd);
        }

        break;

    default:
        break;
    }
}