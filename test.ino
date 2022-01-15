#include <LC75342.h>

LC75342 lc(2,3,4);   // CE,DI,CL

void setup(){
  audio();
  }

void loop(){}

void audio(){
  lc.addr();
  lc.set_input(0);   // input 1...4 = byte 0...3 (byte 4...7 = All switches off)
  lc.set_gain(0);    // gain 0...30 dB step 2 dB = byte 0...15
  lc.set_volume(0);  // volume 0...-79 dB = byte 0...79
  lc.set_treble(0);  // treble 10...-10 dB step 2 dB = int 5...-5 
  lc.set_bass(0);    // bass 20...-20 dB step 2 dB = int 10...-10
  lc.set_ch(3);      // Channel Selection RCH = byte 2, LCH = byte 1, Left and right together = byte 3 
  lc.test();
  }
