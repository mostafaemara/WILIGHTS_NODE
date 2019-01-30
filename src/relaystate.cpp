
#include"relaystate.h"




void save_relay_state(unsigned char relayno,unsigned char state){

int addr=relayno+64;

    system_rtc_mem_write(addr,&state,sizeof(state));
}

unsigned char get_relay_state(unsigned char relayno){

unsigned char state;
int addr=relayno+64;


 system_rtc_mem_read(addr,&state,sizeof(state));
 if (state==1){
return 1;

 }else{
 return 2;
 }
}