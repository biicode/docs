#include "blink.h"

Blink my_blink;

void setup() {
  my_blink.blink_setup(13, 1000); //pin = 13, interval = 1000 ms,
}

// bii:#entry_point()
void loop(){

  my_blink.blink_loop();
  //you can do other things here, blink won't block
  
}