/**
 * @file gcd.cpp
 * 
 * @brief 
 * The idea is, GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number. 
 * More about  Euclidean algorithm-> https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
 * @details 
 * Time Complexity: O(min(a,b))
 * Auxiliary Space: O(min(a,b))
 * @author Akash (https://github.com/aka-0803)
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

// Driver code
// prints GCD 
int main()
{
    int a = 10, b = 20;
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gcd(a, b);
    return 0;
}