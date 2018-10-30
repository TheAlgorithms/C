#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void toh(int n,char* s,char* d,char* a) {
	count++;
	if(n==1)
		printf("\nMove disk %d from %s to %s",n,s,d);
	else {
		toh(n-1,s,a,d);
		printf("\nMove disk %d from %s to %s",n,s,d);
		toh(n-1,d,s,a);
	}
}

int main() {
	int num;
	srand(time(NULL));
	num=rand()%10+1;
	printf("\nNumber of Disks : %d\n",num);
	toh(num,"Source","Destination","Auxiliary");
	printf("\n\nTotal number of steps : %d\n\n",count);
	return 0;
}
