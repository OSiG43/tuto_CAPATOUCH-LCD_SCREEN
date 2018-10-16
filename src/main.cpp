#include "Arduino.h"
#include "Wire.h"
#include "Adafruit_MPR121.h"

char keyToChar(uint16_t key);


Adafruit_MPR121 touch;

void setup(){
    Serial.begin(9600);
    Serial.println("Capacitive Touch numpad test start");
    if(!touch.begin(0x5A)){
        Serial.println("touch numpad not found");
        Serial.println("Start scan");
        uint16_t i;
        bool found =false;
        for(i=0;i<500;i++){
            if(touch.begin(i)){
                Serial.print("touch numpad found at adress: ");
                Serial.println(i);
                found = true;
                break;
            }
            Serial.print("touch numpad not found at adress: ");
            Serial.println(i);
        }
        if(!found){
            Serial.println("Touch pad not found: exit");
            while(1);
        }

    }
}


uint16_t keytouch = 0;
void loop(){
    keytouch=touch.touched();
    Serial.println(keyToChar(keytouch));
    

}

char keyToChar(uint16_t key){
        switch (key)
    {
        case 1:
            return '1';

        case 16:
            return '2';

        case 256:
            return '3';

        case 2:
            return '4';
        
        case 32:
            return '5';

        case 512:
            return '6';

        case 4:
            return '7';

        case 64:
            return '8';

        case 1024:
            return '9';
        
        case 8:
            return '*';

        case 128:
            return '0';

        case 2048:
            return '#';

        default:
            return 0;
    }
}