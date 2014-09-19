#include "your_user_name/arduino_blink/blink.h"

Blink my_reuse_blink;

void setup() {
  my_reuse_blink.setup(13, 1000); 
}

void loop(){
  my_reuse_blink.loop();  
}