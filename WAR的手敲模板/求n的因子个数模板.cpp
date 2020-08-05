#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
const ll mod=1e9+7;

ll CountFactor(ll n)
{
	ll ans=0;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans++;
			if(i!=n/i)ans++;
		}
	}
	return ans;
}

int main()
{
	ll n;
	scanf("%lld",&n);
	printf("%lld\n",CountFactor(n));
}
