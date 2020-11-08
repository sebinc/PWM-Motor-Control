#include<reg51.h>


////////////////////////////////////////////////////////
//__________Definitions for PORT_______________/////////
////////////////////////////////////////////////////////
#define adc_data P1

///////////////////////////////////////////////////////
////___________Bit definitions_____________________////
///////////////////////////////////////////////////////

sbit rd= P3^7;
sbit wr= P3^6;
sbit motor1= P2^0;
sbit motor2= P2^1;
sbit intr= P3^4;
sbit en= P2^2;
sbit dir =P3^0;


unsigned char read_adc(void);
void delay(unsigned char);




//_________________________________________________________//
//_______________________MAIN.C____________________________//
//_________________________________________________________//




void main()
{
	
	unsigned char port_data;   //variables
	
	adc_data=0xff;                           // configure port 1 as input
	P2=0x00;			   				           // temparery
	P3=0xff;
	
	motor1=1;
	motor2=0;            //Assigns motor to the forward direction
	
	while(1)
	{
		 
    port_data= read_adc();
		
		en=1;
		delay(port_data);
		
		en=0;
		port_data=255-port_data;
		delay(port_data);
		
		if(dir==1)
		{
			motor1=1;
     	motor2=0; 
		}
		else
			{
			motor1=0;
     	motor2=1; 
		 }
	
	
	}
	
}






////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Function Definitions///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////


unsigned char read_adc(void)
{
	wr=0;
	delay(1);
	rd=1;
	wr=1;
	intr=1;
	while(intr==1);
	delay(1);
	rd=0;
	return adc_data;
}



void delay(unsigned char x )
{
	unsigned char i,j;
	for(i=0;i<50;i++)
	{
		for(j=0;j<x;j++);
	}
}