#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
const ll maxn = 10000005;
const ll mod = 1e9 + 7;
bool a[maxn];
ll n,m;
void prime()
{
    a[1] = a[0] = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(a[i] == 0)
        {
            for(int j = 2 * i; j <= n; j += i)
            {
                a[j] = 1;
            } 
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
 
    
    cin >> n >> m;
    prime();
    while(m--)
    {
		ll p;
		cin >> p;
		if(!a[p])cout << "Yes" << endl;
		else cout << "No" << endl;
    }
    return 0;
}

