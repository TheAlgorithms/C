//Returns the sorted array after performing SlowSort
//This algorithm works on multiply and surrender principle



void SlowSort(int a[], int i, int j)
{
  if(i>=j)
    return;
  int m=i+(j-i)/2;
  int temp;
  SlowSort(a, i, m);
  SlowSort(a, m + 1, j);
  if(a[j]<a[m])
  {
    temp=a[j];
    a[j]=a[m];
    a[m]=temp;
  }
  SlowSort(a, i, j - 1);
}
