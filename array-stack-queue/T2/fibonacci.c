#include<stdio.h>
#include<time.h>
#include<malloc.h>

long double fib(int n) {

	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else 
		return fib(n-1)+fib(n-2);
}

long double memoizeFib(int n, long double helpmem[]) {
    if(n == 1)
        return 0;
    if (n == 2)
        return 1;
    if(helpmem[n] != 0)
        return helpmem[n];
    else
    {
        helpmem[n] = memoizeFib(n-1,helpmem) + memoizeFib(n-2,helpmem);
        return helpmem[n];
    }
}

int main() {	
	clock_t start,end,start1,end1;
	int n,i,j;
	long double res,helpmem[10001];
	FILE *f;
	printf("\nEnter number of terms :\n");
	scanf("%d",&n);
	for(i=0;i<10000;++i)
		helpmem[i]=0;
/*	helpmem=(long int *)calloc(n,sizeof(long int));

	start=clock();
	res=fib(n);
	end=clock();
	printf("\nResult :\t%ld\t Time :\t%lf\n\n",res,(((double)(end-start))/CLOCKS_PER_SEC));
*/
	fopen("file.txt",'w');
	for(j=0;j<=10000;j=j+1000) {
		for(i=0;i<10000;++i)
			helpmem[i]=0;
		start1=clock();
		res=memoizeFib(j,helpmem);
		end1=clock();
		fprintf(f,"%llf\t%lf",res,(((double)(end1-start1))/CLOCKS_PER_SEC));
		printf("\nResult :\t%llf\t Time :\t%lf\n\n",res,(((double)(end1-start1))/CLOCKS_PER_SEC));
	}
	fclose(f);
	return 0;
}
