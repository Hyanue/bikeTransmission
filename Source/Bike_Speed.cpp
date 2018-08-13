// 
// 
// 
#include <Arduino.h>
#include "control.h"
#include "Bike_Speed.h"

#define speed_wait_time 5//测速最小间隔
unsigned long speed_time[4];//测速时间数据组
unsigned long speed_last_time = 0;//上一次测速时间
int speed_num = 0;//当前时间数据在数组中的位置

void Speed_init() {
	pinMode(Speed_pin, INPUT);
}

void Getspeed() {
	double speed_sum = 0;
	detachInterrupt(Speed_pin);

	if (millis() - speed_last_time >= speed_wait_time && millis() - speed_last_time <= 1000)//speed data is valid
	{
		speed_time[speed_num] = (millis() - speed_last_time);//save speed data;
		if (3 == speed_num)
		{
			speed_num = 0;
		}
		else
		{
			speed_num++;
		}
	}
	speed_last_time = millis();
	for (int i = 0; i < 4; i++)
	{
		speed_sum += speed_time[i];
	}

	Speed = 60000 / (speed_sum * 2);
	attachInterrupt(digitalPinToInterrupt(Speed_pin), Getspeed, RISING);
	LCD_display_flag = 1;
}
