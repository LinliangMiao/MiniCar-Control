sbit PWM0=P2^0;
sbit PWM1=P2^1;
sbit PWM2=P2^2;
sbit PWM3=P2^3;

sbit IN0=P1^0;
sbit IN1=P1^1;
sbit IN2=P1^2;
sbit IN3=P1^3;
sbit IN4=P1^4;
sbit IN5=P1^5;
sbit IN6=P1^6;
sbit IN7=P1^7;

void MotorStop(void);
void StraightRun(unsigned char m);
void TurnRight(unsigned char n);
void TurnLeft(unsigned char k);