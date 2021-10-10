//Rotation of array that rotates arr[] of size n by d elements
#include<iostream>
using namespace std;
int rotate(int arr[],int d,int n);
int main()
{
  int n,d;
  cin>>n;
  int arr[n];
  int i;

	for(i=0;i<n;i++)
		cin>>arr[i];

	cin>>d;
	rotate(arr,d,n);

	cout<<"\nAfter Rotation : \n";

	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";

  return 0;
}

int rotate(int arr[],int d,int n)
{
	int i,j;
	int temp[d];

	for(i=0;i<d;i++)
		temp[i]=arr[i];

	j=d;

	for(i=0;i<n-d;i++)
	{
		arr[i]=arr[j];
		j++;
	}

	j=0;

	for(i=n-d;i<n;i++)
	{
		arr[i]=temp[j];
		j++;
	}

}
