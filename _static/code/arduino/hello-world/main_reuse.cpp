#include "your_user_name/arduino_block/blink.h"

void setup() {                
	blink_setup(13, 4000); // //Led pin 13, 4000ms interval
}

void loop() {
	blink_loop();
}