#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
	
uint temp=0;
void Delay(unsigned int i)
{	
	unsigned int j;		
	for(;i>0;i--)
	for(j=0;j<125;j++);	
}

void  main( )		
 {
	TMOD=0x60;		//定时器工作方式计数器模式，T1，工作模式2（自动复位）
	TH1=(256-16);		//每16脉冲1个中断，1圈256个脉冲共触发中断16次
	TL1=(256-16);		
	EA=1;    			
	ET1=1;   		  
 	TR1=1;   			
 	while(1) ;		  	
 }

void T1_int(void)  interrupt 3  	
{
	
	if(temp==15)
	{
	
 		P1=0x00;			
 		Delay(500); 
		P1=0xff;
		temp=0;
	}
	else temp++;
}


						
