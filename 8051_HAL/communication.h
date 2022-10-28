






#ifndef COMMUNICATION_H_INCLUDED
#define COMMUNICATION_H_INCLUDED



#endif // COMMUNICATION_H_INCLUDED

#include<reg51.h>







// serial communication transciever mode





void serial_trans(int baud,int Data){

	SCON = 0x50;
	
	TMOD = 0X20;
	TH1 = baud;
	TR1 =  1;
	
	SBUF = Data;
	
	while(TI == 0);
	TI = 0;
	
}



//serial communication receiver



int serial_rec(int baud){
	
	int Data;
	
	SCON = 0x50;
	
	TMOD = 0X20;
	TH1 = baud;
	TR1 =  1;
	
	Data = SBUF;
	
	while(RI == 0);
	RI = 0;
}

