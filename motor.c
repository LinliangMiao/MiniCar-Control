#include<reg52.h>
#include<motor.h>
#include<delay.h>

extern unsigned char time0; 
extern unsigned char duty;

void MotorStop()
{
	PWM0=0;PWM1=0;
	PWM2=0;PWM3=0;

	IN0=0;IN1=0;
  IN2=0;IN3=0;
	IN4=0;IN5=0;
	IN6=0;IN7=0;
	
	Delayms(20);
}

void TurnLeft(unsigned char m)
{
	duty=m;
	IN0=1;IN1=0;
  IN2=0;IN3=0;
	IN4=0;IN5=0;
	IN6=1;IN7=0;
}

void TurnRight(unsigned char n)
{
	duty=n;
	IN0=0;IN1=0;
  IN2=1;IN3=0;
	IN4=1;IN5=0;
	IN6=0;IN7=0;
}

void StraightRun(unsigned char k)
{
	duty=k;
	IN0=1;IN1=0;
  IN2=1;IN3=0;
	IN4=1;IN5=0;
	IN6=1;IN7=0;
}