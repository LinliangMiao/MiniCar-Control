#include<reg52.h>
#include<serial.h>
#include<delay.h>

/*
void SerialInit(){
 TMOD=0x20;  
 TH1=0xfd; 
 TL1=0xfd; 
 TR1=1;  
 SM0=0;  
 SM1=1;  
 REN=1;  

 EA=1; 
 ES=1; 
}
*/

void SerialInit(){
 	 PCON &= 0x7F;      
     SCON = 0x50;      
     T2CON  = 0x34;   
     RCAP2H = 0xFF;    
     RCAP2L = 0xDC;  
     TH2    = 0xFF;  
     TL2    = 0xDC;
	   
	 EA=1; 
     ES = 1;     

}



void SerialPortInte(void) interrupt 4 
{
	 unsigned char rbyte;
	 if(RI){     
         RI=0;
		 rbyte=SBUF; 
		 if(rbyte==0x0A){ 	  
		    SendString("??");
		 }else if(rbyte==0x0D){
		 	SendString("??");
		 }else{
		 	SendByte(rbyte); 
		 }
		 	
     }
}


void SendByte(unsigned char sbyte)
{ 
     SBUF=sbyte; 
     while(!TI); 
     TI=0; 
}

void SendString(unsigned char *pstr) 
{
     while(*pstr!='\0') 
     {
         SendByte(*pstr);
         pstr++; 
     }
}