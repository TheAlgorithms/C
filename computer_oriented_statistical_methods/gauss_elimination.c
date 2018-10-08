#include<stdio.h>
#include<conio.h>
void display(float a[20][20],int n)
{
	  int i,j;
	  for(i=0;i<n;i++)
	  {
		    for(j=0;j<=n;j++)
		    {
			      printf("%.2f \t",a[i][j]);
		    }
		    printf("\n");
	  }
}
float interchange(float m[20][20],int i,int n)
{
	  float tmp[20][20];
	  float max=fabs(m[i][i]);
	  int j,k=i;

	  for(j=i;j<n;j++)
	  {
		    if(max<fabs(m[j][i]))
		    {
			      max=fabs(m[j][i]);
			      k=j;
		    }
	  }
	  for(j=0;j<=n;j++)
	  {
		    tmp[i][j]=m[i][j];
		    m[i][j]=m[k][j];
		    m[k][j]=tmp[i][j];
	  }
	  return m[20][20];
}
float eliminate(float m[20][20],int i,int n)
{
	float tmp;
	int k=1,l,j;
	for(j=i;j<n-1;j++)
	{
		  tmp=-((m[i+k][i])/(m[i][i]));
		  for(l=0;l<=n;l++)
		  {
			    m[i+k][l]=(m[i+k][l])+(m[i][l]*tmp);
		  }
		  k++;
	}
	return m[20][20];
}
void main()
{
	  int i,j,n,k=0,l;
	  float m[20][20],mul,tmp[20][20],val,ans[20];
	  clrscr();

	  printf("Total No.of Equations : ");
	  scanf("%d",&n);

	  printf("\n");
	  for(i=0;i<n;i++)
	  {

		    printf("Enter Co-efficient Of Equations %d & Total --->>>\n",i+1);
		    for(j=0;j<=n;j++)
		    {
			      printf("r%d%d : ",i,j);
			      scanf("%f",&m[i][j]);
		    }
		    printf("\n");
	  }
	  printf(":::::::::::: Current Matrix ::::::::::::\n\n");
	  display(m,n);

	 for(i=0;i<n-1;i++)
	 {
		    printf("\n------->>>>>>>>>>>>>>>>>>>>>>>>-------- %d\n",i+1);
		    m[20][20]=interchange(m,i,n);
		    display(m,n);
		    printf("\n_______________________________________\n");
		    m[20][20]=eliminate(m,i,n);
		    display(m,n);
	  }
	  printf("\n\n Values are : \n");
	 for(i=n-1;i>=0;i--)
	  {
		    l=n-1;
		    mul=0;
		    for(j=0;j<k;j++)
		    {
			    mul=mul+m[i][l]*ans[l];
			    l--;
		    }
		    k++;
		    ans[i]=(m[i][n]-mul)/m[i][i];
		    printf("X%d = %.2f\n",i+1,ans[i]);
	  }
getch();
}
