#include "blink.h"

void setup() {
  // set the digital pin as output:
  blink_setup(13, 1000); //Led pin 13, 1000ms interval     
}

void loop(){
  blink_loop();
  //you can do other things here, blink won't block
}