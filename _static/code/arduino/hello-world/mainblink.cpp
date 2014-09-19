#include "blink.h"

Blink my_blink;

void setup() {
  my_blink.setup(13, 1000); //pin = 13, interval = 1000 ms,
}

void loop(){

  my_blink.loop();
  //you can do other things here, blink won't block
  
}