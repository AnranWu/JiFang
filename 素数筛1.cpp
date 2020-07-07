#include <bits/stdc++.h>
#define maxn 10000005
typedef long long ll;
using namespace std;
ll n,m;
ll prime(ll n)
{
    if(n < 2)return 0;
    if(n ==2 || n == 3)return 1;
    if(n % 6 != 1 && n % 6 != 5)return 0;
    for(ll i = 5; i * i <= n; i += 6)
    {
        if(n % i == 0 || n % (i + 2) == 0)
        return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    while(m--)
    {
        ll x;
        cin >> x;
        if(prime(x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

