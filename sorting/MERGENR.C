/* Program to demonstrate non recursive merge sort */

#include  <stdio.h>

void  mergesort(int  x[ ] , int  n) ; 
void  show(int  x[ ] , int  n) ;



void  mergesort(int  x[ ] , int  n)
{
  int  temp[50] , i , j , k , lb1 , lb2 , ub1 , ub2 , size ;

  size=1 ;
  while(size<n)
  {
    lb1=0 ;
    k=0 ;

    while(lb1+size<n)
    {
      lb2=lb1+size ;
      ub1=lb2-1 ;
      if(ub1+size<n)
		ub2=ub1+size ;
      else
		ub2=n-1 ;

      i=lb1 ;
      j=lb2 ;

      while(i<=ub1&&j<=ub2)
		if(x[i]<x[j])
	  		temp[k++]=x[i++] ;
		else
	  		temp[k++]=x[j++] ;

      while(i<=ub1)
		temp[k++]=x[i++] ;

      while(j<=ub2)
		temp[k++]=x[j++] ;

      lb1=ub2+1 ;
    }

    for(i=0 ; i<=ub2 ; i++)
      x[i]=temp[i] ;

    size=size*2 ;

    show(x,n) ;
  }
}

// function to show each pass
void  show(int  x[ ] , int  n)
{
  int  i ;
  for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
  printf("\n\n") ;
}


int  main() //main function
{
 int  i , n , x[20] ;

 printf("Enter the number of elements: ") ;
 scanf("%d",&n) ;
 printf("Enter the elements:\n") ;
 for(i=0 ; i<n ; i++)
    scanf("%d",&x[i]) ;

 mergesort(x,n) ;

 printf("Sorted array is as shown:\n") ;
 for(i=0 ; i<n ; i++)
    printf("%d " , x[i]) ;
 return 0;
}
