#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long

vector<ll> v(1e7, 0);
int a()
{
    v[1] = 1;
    v[2] = 2;
    for (ll i = 3; i <= 1e7; i++)
        v[i] = v[i - 1] + i - 1;
}
int b()
{
    ll k;
    cin >> k;
    ll n;
    n = lower_bound(v.begin(), v.end(), k + 1) - v.begin() - 1;
    cout << 2 * n << endl;
}
int main()
{
    fastio();
    ll t;
    cin >> t;
    a();
    while (t-- != 0)
    {
        b();
    }
    return 0;
}