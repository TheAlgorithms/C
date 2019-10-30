#include <stdio.h>

void swap (int *a,int *b)//To swap the variables//
{
    int t;
    t= *a;
    *a=*b;
    *b=t;
    
}

void merge(int a[],int l,int r,int n)//To merge //
{  int *b = (int*)malloc(n*sizeof(int));
int c=l;
    int p1,p2;
    p1 = l;p2=((l+r)/2)+1;
    while ((p1<((l+r)/2)+1) &&(p2<r+1))
    { if(a[p1] <= a[p2])
{          b[c++] = a[p1];
           p1++;
}
          else
          {b[c++] = a[p2];p2++;}
        
    };
    
    if (p2 == r+1)
    {
       while ((p1<((l+r)/2)+1))
    { 
          b[c++] = a[p1];
            p1++;
    }; 
        
    }
    else
    {
          while ((p2<r+1))
    { 
          b[c++] = a[p2];
p2++;
    }; 
         }
         
        for (c=l;c<r-l+1;c++)
        a[c] = b[c];
    
}
void mergesort(int a[],int n,int l,int r)
{
    if (r-l == 1 )
    {
        if (a[l]>a[r])
        swap(&a[l],&a[r]);
        
    }
    else if(l==r)
    {}
    else
    {mergesort(a,n,l,(l+r)/2);
     mergesort(a,n,((l+r)/2)+1,r);
       merge(a,l,r,n);
        
    }
    
}
int main(void) {   //main function//
int *a,n,i;
scanf("%d",&n);
a = (int*)malloc(n*sizeof(int));
for (i=0;i<n;i++)
{
    
    scanf("%d",&a[i]);
    
}

mergesort(a,n,0,n-1);
for (i=0;i<n;i++)
{
    
    printf(" %d",&a[i]);
    
}


	return 0;
}



