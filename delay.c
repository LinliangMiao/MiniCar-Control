#include<reg52.h>
#include<delay.h>

void Delayms(unsigned int i)  
{
    unsigned int j;
    while(i--)
    {
        for(j = 0; j < 125; j++);
    }
}