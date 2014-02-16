#include "blink.h"

void setup() {
  blink_setup(13, 1000); //Led pin 13, 1000ms interval     
}

// bii:#entry_point()
void loop(){
  blink_loop();
  //you can do other things here, blink won't block
}