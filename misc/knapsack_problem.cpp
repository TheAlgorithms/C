#include<iostream>
using namespace std;

int main()
{
	int w[]={6,10,3,5,1,3};//Hard-coded values of weights and values.
	int v[]={6,2,1,8,3,5};//'v' and 'w' can be taken as inputs
	double vw[6];
	for(int i=0;i<6;i++)
	{
		vw[i]=(double)(v[i])/w[i];
	}
	double max=0;
	int m1;
	printf("Enter the capacity : ");
	scanf("%d",&m1);
	int ci=0;
	double tv=0;
	int tw=0;
	do
	{
		max=0;
		for(int i=0;i<6;i++)
		{
			if(vw[i]>max)
			{
				max=vw[i];
				ci=i;
			}
		}
		if(max!=0)
		{
			if(m1-(tw+w[ci])>=0)
			{
				tv=tv+v[ci];
				tw=tw+w[ci];
				cout<<"i"<<(ci+1)<<" : 1"<<endl;
				vw[ci]=0;
			}
			else
			{
				double r = (double)(m1-tw)/w[ci];
				tv=tv+(r*v[ci]);
				cout<<"i"<<(ci+1)<<" : "<<r<<endl;
				break;
			}
		}
	}while(max!=0 &&  tw<m1);
	cout<<"Total value : "<<tv;
}
