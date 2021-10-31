#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
  int largest = i; 
  int l = 2 * i + 1; 
  int r = 2 * i + 2; 

  if (l < n && arr[l] > arr[largest])
    largest = l;
  
  if (r < n && arr[r] > arr[largest])
    largest = r;
  
  if (largest != i) 
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void buildHeap(int arr[], int n)
{
  int st = (n / 2) - 1;
  for (int i = st; i >= 0; i--) 
  {
    heapify(arr, n, i);
  }
}

void heapSort(int arr[], int n)
{
  buildHeap(arr,n);
  for (int i = n - 1; i > 0; i--) 
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void printHeap(int arr[],int n)
{
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
  
  cout << "\n";
}

void descending(int arr[],int n)
{
  int temp=0;
  int B[n];
  for(int i=0;i<n;i++)
  {
    B[i]=arr[i];
  }

  for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(B[i]<B[j])
			{
				temp=B[i];
				B[i]=B[j];
				B[j]=temp;
			}
		}
	}
	
  cout<<"The array in descending order\n";
  for(int i=0;i<n;i++)
  {
    cout<<B[i]<<" ";
  }
}

int main()
{
  int n,arr[n];
  int c,max=0,e=0;
  while(c!=1)
  {
    cout<<"1.Quit(Type -1 to quit)\n";
    cout<<"2.N Random elements =>Array\n";
    cout<<"3.Display Array\n";
    cout<<"4.Sort in ascending order\n";
    cout<<"5.Sort in descending order\n";
    cout<<"6.Replace a node with a new value\n";
    cout<<"7.Insert a element\n";
    cout<<"8.Delete a element\n";
    cin>>c;

    switch(c)
    {
      case 1: cout<<"Program ended!!!\n";
              break;
      
      case 2: {
                cout<<"Inserting n random no's to array\n";
                cout<<"Enter 11 elements:-\n";
                for(int i=0;i<11;i++)
                {
                  cin>>arr[i];
                }
                n=sizeof(arr)/sizeof(int);
              }
              break;
      
      case 3:{
               heapSort(arr,n);
               cout<<"The elements are sorted in ascending order\n";
             }
             break;

      case 4:{
               descending(arr,n);
             }
             break;

      case 5:{
               max=arr[n-1];
               cout<<"The max element is:- "<<max<<endl;
             }
             break;

      case 6:{
               cout<<"Enter the element new value:-\n";
               cin>>e;

               arr[n]=e;
             }
             break;

      case 7:{
               cout<<"Enter the new element to be inserted:- \n";
               cin>>e;
               
               n++;
               arr[n]=e;
             }
             break;

      case 8:{
               cout<<"Last element deletion\n";

               n--;
             }
  }
}
}