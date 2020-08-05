#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
const ll mod=1e9+7;

ll fac(ll n,ll k)
{
	ll ans=0;
	for(ll i=1;i*i<=n;i++)
	{
		if(i>k)break;
		if(n%i==0)
		{
			ans++;
			if(n/i<=k&&n/i!=i)ans++;
		}
	}
	return ans;
}

int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll ans=0;
	
	ll mi=min(n,k);
	
	for(ll i=2,j;i<=mi;i=j+1)
	{
		j=n/(n/i);
		j=min(mi,j);
		ans=(ans+(((j-i+1)%mod)*(n/i))%mod)%mod;
	}
	ans=(ans*2)%mod;
	ans=(ans+(n%mod))%mod;
	ans=(ans+(max(k-n,0ll)%mod))%mod;
	ans=(ans+((mi-fac(n,mi))%mod))%mod;
	printf("%lld\n",ans);
}
