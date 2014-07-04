#include "led.h"

Led::Led()
{
	pin = 0;
	wiringPiSetup () ;
	pinMode (pin, OUTPUT) ;
}

Led::~Led()
{

}

void Led::on()
{
	digitalWrite (pin, HIGH);
}

void Led::off()
{
	digitalWrite (pin, LOW);
}