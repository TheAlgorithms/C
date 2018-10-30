/*  This code requires the packages gnuplot and gnuplot-x11
to be installed on the system, otherwise the plotting will not
work. The program takes an argument which is the term of the
Fibonacci series to be computed and uses both naive recursion
and top-down dynamic programming with memoization.  */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int naive_fib(int n) {
    return (n<2)?n:naive_fib(n-1)+naive_fib(n-2);
}
int fib_memoization(int n, int* f) {
    // use top-down dp approach with memoization.
    if (f[n]==-1)
    	f[n]=fib_memoization(n-1,f)+fib_memoization(n-2,f);
    return f[n];
}
int main(int argc, char**argv) {
    if (argc!=2) {
        printf("Invalid options. Format: <program> <number>\n");
        printf("Args:number: The Fibonacci term to compute.");
        return -1;
    }    
    int param=atoi(argv[1]);
    
    int f[param+1]; // used in the memoization approach
    f[0]=0; f[1]=1;
    int i;
    for (i=2;i<=param;++i) f[i]=-1;
    
    clock_t start, end;
    double time1,time2;
    printf("Naive recursion:\n");
    start=clock();
    int val=naive_fib(param);
    end=clock();
    time1=(double)(end-start)/CLOCKS_PER_SEC*1000;
    printf("Value:%d\nTime taken:%lf\n",val,time1);
    printf("Top-down DP approach with memoization:\n");
    start=clock();
    val=fib_memoization(param,f);
    end=clock();
    time2=(double)(end-start)/CLOCKS_PER_SEC*1000;
    printf("Value:%d\nTime taken:%lf\n",val,time2);
    // now plot
    //char* commands[]={"set title\"TIMES TAKEN IN MS\"","set xrange [0:3]","plot "
      //              "'data.tmp' using 1:2:(sprintf(\"%d, %d\"), $1, $2) with"
        //            " labels point pt 7 offset char 1,1 notitle"};
    char* commands[] = {"set title \"TIMES TAKEN IN MS\"","set xrange [0:3]","plot 'data.tmp' with lines"};
    double xvals[]={1.0,2.0}; // or whatever.
    double yvals[]={time1,time2};
    FILE* tmp=fopen("data.tmp","w");
    FILE* gnuplotPipe=popen("gnuplot -persistent","w");
    for (i=0;i<2;++i) fprintf(tmp,"%lf %lf\n",xvals[i],yvals[i]);
    for (i=0;i<3;++i) fprintf(gnuplotPipe,"%s \n", commands[i]);    
    fflush(gnuplotPipe);
    fclose(tmp);
    return 0;   
}
