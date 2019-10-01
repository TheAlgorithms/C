// CALCULATING nCr IN SHORT TIME BUT MAY LEAD TO OVERFLOW FOR VERY LARGE NUMBERS

/*  AUTHOR:AKASH JAIN
*   USERNAME:akash19jain    
*   
*/

ll ncr(ll n,ll r)
{
    if(r>n-r)
        r=n-r;      //nCr = nC(n-r)
    ll ans=1;
    FOR(i,1,r)
    {
        ans*=n-r+i;
        ans/=i;
    }
    return ans;
}

/*This code will start multiplication of the numerator from the smaller end, 
and as the product of any k consecutive integers is divisible by k!, 
there will be no divisibility problem. But the possibility of overflow is still there, 
another useful trick may be dividing n - r + i and i by their GCD before doing the multiplication 
and division (and still overflow may occur).*/
