void setup() {
#include <Tlc5940.h>
#include <tlc_animations.h>
#include <tlc_config.h>
#include <tlc_fades.h>
#include <tlc_progmem_utils.h>
#include <tlc_servos.h>
#include <tlc_shifts.h>

Tlc.init();

}//end setup

void loop() {

  byte shift1[8];
  byte shift2[3];

//first shifter
shift1[0] = 0x80; //10000000
shift1[1] = 0x40; //01000000
shift1[2] = 0x20; //00100000
shift1[3] = 0x10; //00010000
shift1[4] = 0x8;  //00001000
shift1[5] = 0x4;  //00000100
shift1[6] = 0x2;  //00000010
shift1[7] = 0x1;  //00000001

//second shifter
shift2[0] = 0x80; //10000000
shift2[1] = 0x40; //01000000
shift2[2] = 0x20; //00100000

  // for loop to set coloumns
  for (col = 0; col == 10; col++){
    
    // for loop to set rows
    for (row = 0; row == 9; row++){
      Tlc.set(row, input[row]*4095);
      tlc.update();
      }//end for loop row
      
   int rcol; //real column
   if (col  <= 7){
     rcol = col;
     data = shift1[rcol];

    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, data);
    digitalWrite(latchPin, 1);
   }//end if
   else {
     rcol = col - 7;
       data = shift2[rcol];
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, data);
    digitalWrite(latchPin, 1);
   }//end else

  }//end for loop col
  
}//end void loop
