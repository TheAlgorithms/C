/*



*/


#ifndef INTERRUPTS_H_INCLUDED
#define INTERRUPTS_H_INCLUDED



#endif // INTERRUPTS_H_INCLUDED



#include<reg51.h>

sbit int0 = P3^2;
sbit int1 = P3^3;






// external interupt 0





void ext_0(){

	IE = 0x80;

}




// external interupt 1




void ext_1(){

	IE = 0x82;

}






// interupt priority 

/*




*/


void ext_priority(int a){

	if(a == 0){
		IP = 0x01;
	}
	
	
	else if (a == 1){
		IP = 0x04;
	}
	
	
	else
		IP = 0x00;
	
	
}



