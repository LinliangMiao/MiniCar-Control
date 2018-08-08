#include<reg52.h>
#include<serial.h>
#include<delay.h>
#include<motor.h>
#define uint unsigned int
#define uchar unsigned char
unsigned char time0;
unsigned char duty;
void Timer0Init();

void main()
{
	duty=15;
  Timer0Init();
	SerialInit();
	
	while(1)
	{		
		SendString("uio90");Delayms(1000);	
    StraightRun(15);Delayms(1000);		
	  TurnLeft(15);Delayms(1000);		
	  TurnRight(15);Delayms(2000);		
	}			
}
void Timer0Init()
{
	TMOD=0x01;
	TH0=(65536-100)/256;
	TL0=(65536-100)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void tim0() interrupt 1
{
	TR0=0;
	TH0=(65536-100)/256;
	TL0=(65536-100)%256;
	TR0=1;
 
	time0++;
	
	if(time0>=100)  //100Hz
	{
	time0=0;
	}   
	if(time0<=duty)  
	{
	PWM0=1;PWM1=1;PWM2=1;PWM3=1;
	}  
	else 
	{
	PWM0=0;PWM1=0;PWM2=0;PWM3=0;
	}
}
