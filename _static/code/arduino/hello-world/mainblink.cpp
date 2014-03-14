#include "blink.h"

Blink my_blink;

void setup() {
  my_blink.blink_setup(13, 1000); //pin = 13, interval = 1000 ms,
}

void loop(){

  my_blink.blink_loop();
  //you can do other things here, blink won't block
  
}