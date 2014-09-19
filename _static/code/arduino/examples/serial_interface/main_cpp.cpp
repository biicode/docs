#include "david/serial_cpp/serial.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string incomingData = "";
	string input = "";
	serial serialport('#', ';', "COM8", 9600); //Change the serial port ID!!

	while(1){
		input = serialport.read(); //read a message
		if (input != "") cout << input << "\n";
		else{
			cout << "Enter: ";
			cin >> incomingData;
			incomingData = "#" + incomingData;
			incomingData += ";";
			serialport.writeString(incomingData); //send a message
		}
	}
	return 0;
}