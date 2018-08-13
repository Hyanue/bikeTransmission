// 
// 
// 

#include "Bike_Cadence.h"
#include <Arduino.h>
#include "control.h"


#define	cadence_wait_time 10
unsigned long cadence_time[4];
int cadence_num = 0;
unsigned long cadence_last_time = 0;

void Cadence_init() {
	pinMode(Cadence_pin, INPUT);
}

void Getcadence() {
	double cadence_sum;
	detachInterrupt(Cadence_pin);

	if (millis() - cadence_last_time >= cadence_wait_time && millis() - cadence_last_time <= 500)
	{
		cadence_time[cadence_num] = millis() - cadence_last_time;
		if (3 == cadence_num)
		{
			cadence_num = 0;
		}
		else
		{
			cadence_num++;
		}
	}

	cadence_last_time = millis();

	for (int i = 0; i < 4; i++)
	{
		cadence_sum += cadence_time[i];
	}

	Cadence = 60000 / (cadence_sum * 42 / 2);
	attachInterrupt(digitalPinToInterrupt(Cadence_pin), Getcadence, RISING);
	LCD_display_flag = 1;
}
