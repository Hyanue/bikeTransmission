#include <Arduino.h>
#include <Servo.h>
#include <EEPROM.h>
#include "Servo_control.h"
#include "control.h"

int Servo_Before[3] = {65,98,125}; //Positions of servo before
int Servo_After[7] = { 108,102,93,89,84,79,76};//Positions of servo after



Servo beforeServo;
Servo afterServo;

void servo_init(){
	beforeServo.attach(Servo_pin_before);
	afterServo.attach(Servo_pin_after);
}

void servo_run(){

	int before_now;
	int before_old;
	int after_now;
	int after_old;

	before_now = Servo_Before[GEARS[Gears_now]/10 - 1];
	before_old = Servo_Before[GEARS[Gears_old]/10 - 1];
	after_now = Servo_After[GEARS[Gears_now]%10 - 1];
	after_old = Servo_After[GEARS[Gears_old]%10 - 1];//get servo posotions

	if (Gears_now != Gears_old)
	{
		if (before_now > before_old)
		{
			if (before_now = Servo_Before[1])
			{
				beforeServo.write(before_now + 15);
			}
			else
			{
				beforeServo.write(before_now + 5);
			}
			
		}
		else if (before_now < before_old)
		{
			beforeServo.write(before_now - 5);
		}

		if (after_now > after_old)
		{
			afterServo.write(after_now + 6);
		}
		else if (after_now < after_old)
		{
			afterServo.write(after_now - 6);
		}//Pre-act to attach the gear

	delay(1500);
	beforeServo.write(before_now);//keep the gear
	afterServo.write(after_now);//keep the gear
	
	EEPROM.write(0,Gears_now);
	}
}
