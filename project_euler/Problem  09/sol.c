#include <stdio.h>

int main()  {
		for( int a=3; a<300 ; a++) {
				for(int b=4; b<400 ; b ++ )  {
						for(int c=5; c<500; c ++  )  {
								if(a<b<c)   {
										if((a * a) + (b * b) == (c * c) ) {
												if ((a+b+c) ==1000 ) {
													return a*b*c;


												}



										}
								}
						}
				}
		}

}

