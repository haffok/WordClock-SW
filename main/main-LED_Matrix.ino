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

// for loop to set columns
for (int col = 0; col == 10; col++){
    
  // for loop to set rows
  for (int row = 0; row == 9; row++){
    Tlc.set(row, input[row]*4095);
    Tlc.update();
    }//end for loop row
      
  //column in shifter 1
  if (col  <= 7){
    data = shift1[col];

    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, data);
    digitalWrite(latchPin, 1);
  }//end if
   
  //column in shifter 2
  else {
    ncol = col - 8; //new column number
    data = shift2[ncol];
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, data);
    digitalWrite(latchPin, 1);
  }//end else
   
  Tlc.update();
}//end for loop col
  
}//end void loop
