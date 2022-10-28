#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED



#endif // TIMER_H_INCLUDED


#include<reg51.h>



sbit imp0 = P3^4;
sbit imp1 = P3^5;



//delay in milliseconds



void delay_ms(int ms){

	unsigned int i;
	for(i=0;i<ms;i++)
	{
		TMOD = 0x01;
		TH0 = 77;
		TR0 =1;
		while (TF0 == 0);
		TR0 = 0;
	}

}




//delay in microseconds




void delay_us(int us){

	TMOD = 0x01;
		TH0 = (int)(us/12);
		TR0 =1;
		while (TF0 == 0);
		TR0 = 0;

}





//delay in seconds




void delay(int sec){

	 unsigned int i;
	 for(i=0;i<sec;i++){
		delay_ms(1000);
	 }
}




//external counter 0



int counter_0(){
	imp0 =1;
	TR0 = 1;
	TL0 = 0;
	while(TF0 == 0){
			return(TL0);
	}
 }

 
 
 
 //external counter 1
 
 

 int counter_1(){
	imp1 =1;
	TR1 = 1;
	TL1 = 0;
	while(TF1 == 0){
			return(TL1);
	}
 }
