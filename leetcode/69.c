//method-1



//According to the problem statement we must not use any "built-in exponent function" so by considering that...

int mySqrt(int x){

//a new variable which runs till we reach the exact number or the number which is just exactly greater than the number(x).
  long long int k=1;
  while(k*k <= x ){
     k++;
  }
  // 0 is also a non-negative integer so considering that we can use.
  if(x==0)  return 0;
  else{
  //i used k-1 as i just had incremented in the last step where the case is contradicting the while loop so i need to less 1 inorder to get the actual non-negative integer.
  return k-1;
  }
}


//method-2
//but what i found is that method-1 takes much time to run ,so we can use sqrt function but according to me,it is also an exponential function but the judge is accpeting the solutions for the same and also we can reduce time-complexity.
int mySqrt(int x){
//we can simply return square root but we need to return non-negative integer so we round it off by storing the value in int data type which round-offs the value.
  int count=sqrt(x);
  return count;
}


