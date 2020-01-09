
#include <stdio.h>
#include <stdlib.h>

// Function for Tower of Hanoi algorithm 
void hanoi(int noOfDisks,char where,char to,char extra){
	if(noOfDisks == 0 )
	{
		return;
	}
	else
	{
		hanoi(noOfDisks-1, where, extra , to);
		printf("Move disk : %d from %c to %c\n",noOfDisks,where,to);
		hanoi(noOfDisks-1,extra,to,where);
	}
}
int main(void){
	int noOfDisks;
	
	//Asks the number of disks in the tower 
	printf("Number of disks: \n");
	scanf("%d", &noOfDisks);
	
	hanoi(noOfDisks,'A','B','C');
	
	return 0;

}
