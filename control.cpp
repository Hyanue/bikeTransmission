#include <Arduino.h>
#include "control.h"

void Control_init(){
    pinMode(Add_pin,INPUT);
    pinMode(Reduce_pin,INPUT);
}

int Cadence_available(double ratio){
    double  ratio_practice;
	ratio_practice = Speed / Cadence;
    if(ratio_practice > ratio*0.75&&ratio_practice < ratio*1.25)
        return 1;
    else
        return 0;
}

int Change_gears(){
    int i = Cadence;
    int x = Gears_old;
    while(i > Cadence_MAX){
        if(x < 11){
            x++;
            i = Speed / RATIO[x];
        }
        else{
            i = Cadence_MAX;
        }
    }
    while(i < Cadence_MIN){
        if(x > 0){
            x--;
            i = Speed / RATIO[x];
        }
        else{
            i = Cadence_MIN;
        }
    }
return x;
}

void Auto_mode(){
    if(Cadence < Cadence_MIN || Cadence > Cadence_MAX)
    Gears_old = Gears_now;
    Gears_now = change_Gears();
}

void Manual_mode(){
    //no shaking preventer
    Gears_old = Gears_now;

    if(digitalRead(Add_pin) == LOW && Gears_old < 11){
        Gears_now++;
    }
    else if(digitalRead(Reduce_pin) == LOW && Gears_old > 1){
        Gears_now--;
    }
}