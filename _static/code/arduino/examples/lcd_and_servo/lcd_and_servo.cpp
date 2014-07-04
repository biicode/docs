#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>
	
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myservo;

void write_angle_lcd(int pos){
	lcd.setCursor(0, 1);
	lcd.print(pos);
	lcd.print(" ");
}

void setup(){
	myservo.attach(10);
	lcd.begin(16, 2);
	lcd.print("SERVO ANGLE");
	lcd.setCursor(0, 1);
}
void loop(){
	int pos; 
	for(pos = 0; pos <= 180; pos += 1){
	myservo.write(pos);
	write_angle_lcd(pos);
	delay(50);
	} 
	for(pos = 180; pos >= 0; pos -= 1){                       
	myservo.write(pos);
	write_angle_lcd(pos);
	delay(50);
	} 
}