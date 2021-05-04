#include<reg51.h>
sbit a0=P0^2; 
int j=0;
void delayms(uint)	;



void main(void)
{
	while(1)
	{
	a0=1;
	delayms(500);
	a0=0;
		delayms(500);
	}
	
}

void delayms(uint j)
{
unsigned char i;
for(;j>0;j--)
  	{	
		i=250;
   	 	while(--i);
   	 	i=249;
   	 	while(--i);
   	}
}
