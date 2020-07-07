#include <bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;
ll prime(ll n)
{
    if(n < 2)return 0;
    for(ll i = 2; i * i <= n; i ++)
    if(n%i == 0)
    return 0;
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    while(m--)
    {
        ll x;
        cin >> x;
        if(prime(x))cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

