#include"eeprom.h"
void eeprom_init(void){




}
String eeprom_read_ssid(void){
EEPROM.begin(512);
EEPROM_INFO("\n EEPROM: Start reading SSID \n");
String ssid;

for (int i = 0; i < 32; ++i){
    char c=EEPROM.read(i);
    if(c!=0){
		ssid += c;
    }else{
ssid += c;

        break;
    }
}
return ssid;

}
String eeprom_read_password(void){
EEPROM_INFO("\n EEPROM: Start reading PASSWORD\n");
EEPROM.begin(512);
String password;

for (int i = 0; i < 32; ++i){
    char c=EEPROM.read(32+i);
    if(c!=0){
		password += c;
    }else{
password += c;

        break;
    }
}
return password;


}
void eeprom_write_ssid(String ssid){
EEPROM.begin(512);
EEPROM_INFO("\n EEPROM: Start writing  SSID\n");
for (int i = 0; i < ssid.length(); ++i) {
			EEPROM.write(i, ssid[i]);
		if(i==(ssid.length()-1)){

            EEPROM.write(1+i,0);
        }
        

		}

if(EEPROM.commit()){

EEPROM_INFO("\n EEPROM: Writing  SSID SUCCES\n");

}else{


EEPROM_INFO("\n EEPROM: Writing  SSID  TO EEPROM FAILD\n");
}

}
void eeprom_write_password(String password){
EEPROM.begin(512);
EEPROM_INFO("\n EEPROM: Start writing  PASSWORD\n");
for (int i = 0; i < password.length(); ++i) {
			EEPROM.write(32+i, password[i]);
		if(i==(password.length()-1)){

            EEPROM.write(32+1+i,0);
        }
        

		}

if(EEPROM.commit()){

EEPROM_INFO("\n EEPROM: Writing  PASSWORD SUCCES\n");

}else{


EEPROM_INFO("\n EEPROM: Writing  PASSWORD  TO EEPROM FAILD\n");
}


}