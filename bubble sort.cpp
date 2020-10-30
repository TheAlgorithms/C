#include<iostream>
using namespace std;
int main()
{
	int a[20],n;
	int i,j,flag,temp;
	cout<<"enter the size of the array:";
	cin>>n;
	cout<<"\n the elements of the array:";
	for(i=0;i<n;i++)
	{
		
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
			
		}
		if(flag==0)
		{
			break;
		}
	}
	cout<<"\n the sorted array is:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}
