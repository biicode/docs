#include "your_user_name/arduino_blink/blink.h"

Blink my_reuse_blink;

void setup() {
  my_reuse_blink.blink_setup(13, 1000); 
}

// bii:#entry_point()
void loop(){
  my_reuse_blink.blink_loop();  
}