#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
const ll maxm=1e6+50;
ll c[maxn];

ll lowbit(ll x)
{
	return x&(-x);
}

ll getsum(ll m)
{
	ll sum=0;
	while(m)
	{
		sum+=c[m];
		m-=lowbit(m);
	}
	return sum;
}

void add(ll x,ll val)
{
	while(x<=maxm)
	{
		c[x]+=val;
		x+=lowbit(x);
	}
}

int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF&&n)
	{
		ll ans=0;
		memset(c,0,sizeof(c));
		for(ll i=1;i<=n;i++)
		{
			ll x;
			scanf("%lld",&x);
			add(x+1,1);
			ans+=i-getsum(x+1);//好像不能取到0，这里有点问题，所以+了1 
		}
		printf("%lld\n",ans);
	}
}

