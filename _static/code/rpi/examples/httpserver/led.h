#pragma once

#include <drogon/wiringpi/wiringpi/wiringpi.h>

class Led
{
	public:
		Led(); //default constuctor
		virtual ~Led(); //default virtual destructor
		void on();
		void off();
		
	private:
		int pin;
};