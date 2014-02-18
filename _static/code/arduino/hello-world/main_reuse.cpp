#include "your_user_name/arduino_blink/blink.h"

void setup() {                
	blink_setup(13, 4000); // //Led pin 13, 4000ms interval
}

// bii:#entry_point()
void loop() {
	blink_loop();
}