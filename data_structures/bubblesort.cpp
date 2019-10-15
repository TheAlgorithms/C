#include<iostream>
using namespace std;
main(){
    int a[10];
    cout<<"enter values: ";
        for(int i=0;i<10;++i){
            cin>>a[i];
        }
     for(int i=0;i<10;++i){
              for (int j = 0; j < (10 - i); ++j)  {
                  if(a[j]>a[j+1]){
                      a[j] = a[j] + a[j + 1];
                      a[j + 1] = a[j] - a[j + 1];
                      a[j] = a[j] - a[j + 1];
                  }
              }           
        cou<<"\n sorted array:  ";
        for(int i=0;i<11;++i){
            cout<<a[i]<<" ";
        }
    return 0;
}        
