
#define Add_pin 4
#define Reduce_pin 3
#define Mode_pin 2    //中断引脚支持2,3,18,19,20,21
#define Led_pin 13
#define Cadence_pin 18
#define Speed_pin 19
#define Servo_pin_before 6
#define Servo_pin_after 7
//#define relay_pin 28
#define Battery_pin_1 A3	//7V引脚
#define Battery_pin_2 A2	//4V引脚


extern double Speed;			//车速
extern double Cadence;			//̤踏频
extern int GEARS[12];			//前，后档位排序，由轻向重
extern double RATIO[12];		//传动比
extern int Servo_Before[3];		//前档位的舵机位置
extern int Servo_After[7];		//后档位的舵机位置
extern int Gears_now;			//当前档位顺序，0-11
extern int Gears_old;
extern double Cadence_MAX;		//目标踏频最大值
extern double Cadence_MIN;		//目标踏频最小值
extern int Bike_mode;			//档位模式，0为自动，1为手动
extern int Mode_pin_flag;		//模式切换中断标志
extern int LCD_display_flag;	//显示触发标志


extern void Control_init();
extern int Cadence_available(double ratio);
extern int Change_gears();
extern void Auto_mode();
extern void Manual_mode();
//extern void LCD_Display();
