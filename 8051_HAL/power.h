#ifndef POWER_H_INCLUDED
#define POWER_H_INCLUDED



#endif // POWER_H_INCLUDED

#include<reg51.h>




//idle power mode



void power_idle(){

	
	PCON = 1;

	
}




// power off  mode



void power_off(){
	

	PCON = 2;


}