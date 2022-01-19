#include <Arduino.h>
#include "LC75342.h"

LC75342::LC75342(uint8_t ce, uint8_t di, uint8_t cl){
	CE = ce;
        DI = di;
        CL = cl;
        pinMode(CE,OUTPUT);
        pinMode(DI,OUTPUT);
        pinMode(CL,OUTPUT);
        digitalWrite(CL,LOW);
        digitalWrite(CE,LOW);
        digitalWrite(DI,LOW);
}

void LC75342::addr(){
       digitalWrite(CL,LOW);
       digitalWrite(CE,LOW);
       byte addr = 0b01000001; // 0x82
    for(int i = 7; i >= 0; i--){
       digitalWrite(CL,LOW);
       digitalWrite(DI, (addr >> i) & 0x01);
       digitalWrite(CL,HIGH);
       }  
       digitalWrite(CE,HIGH); 
}

void LC75342::set_input(byte in){
    for(int i = 0; i <= 3; i++){
       digitalWrite(CL,LOW);
       digitalWrite(DI, (in << i) & 0x01);
       digitalWrite(CL,HIGH);
       }
}

void LC75342::set_gain(byte gain){
    for(int i = 0; i <= 3; i++){
       digitalWrite(CL,LOW);
       digitalWrite(DI, (gain << i) & 0x01);
       digitalWrite(CL,HIGH);
       }
}

void LC75342::set_volume(byte vol){
    for(int i = 0; i <= 7; i++){
       digitalWrite(CL,LOW);
       digitalWrite(DI, (vol << i) & 0x01);
       digitalWrite(CL,HIGH);
       }
}

void LC75342::set_treble(int treb){
      switch(treb){
        case 5:  treb = 0b1010;break;//10dB
        case 4:  treb = 0b0010;break;//8dB
        case 3:  treb = 0b1100;break;//6dB
        case 2:  treb = 0b0100;break;//4dB
        case 1:  treb = 0b1000;break;//2dB
        case 0:  treb = 0b0000;break;//0dB
        case -1: treb = 0b1001;break;//-2dB
        case -2: treb = 0b0101;break;//-4dB
        case -3: treb = 0b1101;break;//-6dB
        case -4: treb = 0b0011;break;//-8dB
        case -5: treb = 0b1011;break;//10dB
        }
      for(int i = 3; i >= 0; i--){
        digitalWrite(CL,LOW);
        digitalWrite(DI, (treb >> i) & 0x01);
        digitalWrite(CL,HIGH);
        }
}

void LC75342::set_bass(int bass){
      switch(bass){
        case 10:  bass = 0b010100;break;//20dB
        case 9 :  bass = 0b100100;break;//18dB
        case 8 :  bass = 0b000100;break;//16dB
        case 7 :  bass = 0b111000;break;//14dB
        case 6 :  bass = 0b011000;break;//12dB
        case 5 :  bass = 0b101000;break;//10dB   
        case 4 :  bass = 0b001000;break;//8dB  
        case 3 :  bass = 0b110000;break;//6dB 
        case 2 :  bass = 0b010000;break;//4dB  
        case 1 :  bass = 0b101000;break;//2dB
        case 0 :  bass = 0b000000;break;//0dB
        case -1:  bass = 0b100010;break;//-2dB
        case -2:  bass = 0b010010;break;//-4dB
        case -3:  bass = 0b110010;break;//-6dB
        case -4:  bass = 0b001010;break;//-8dB
        case -5:  bass = 0b101010;break;//-10dB
        case -6:  bass = 0b011010;break;//-12dB
        case -7:  bass = 0b111010;break;//-14dB
        case -8:  bass = 0b000110;break;//-16dB
        case -9:  bass = 0b100110;break;//-18dB
        case -10: bass = 0b010110;break;//-20dB
        }
      for(int i = 5; i >= 0; i--){
        digitalWrite(CL,LOW);
        digitalWrite(DI, (bass >> i) & 0x01);
        digitalWrite(CL,HIGH);
        }
}

void LC75342::set_ch(byte ch){
      switch(ch){
        case 1: ch = 0b01;break;
        case 2: ch = 0b10;break;
        case 3: ch = 0b11;break;
      }
      for(int i = 1; i >= 0; i--){
        digitalWrite(CL,LOW);
        digitalWrite(DI, (ch >> i) & 0x01);
        digitalWrite(CL,HIGH);
        }
}

void LC75342::test(){
      byte test = 0;
      for(int i = 3; i >= 0; i--){
        digitalWrite(CL,LOW);
        digitalWrite(DI, (test >> i) & 0x01);
        digitalWrite(CL,HIGH);
        }
      digitalWrite(CL,LOW);
      digitalWrite(CE,LOW); 
}
