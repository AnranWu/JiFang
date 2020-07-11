#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
typedef long long ll;
const ll maxn=1e6+10;
ll maxm=1e6+10;

ll n,p;
ll sum[maxn];
ll c[maxn];
ll ss[maxn];
ll lowbit(ll x)
{
	return x&(-x);
}

ll getsum(ll m)
{
	ll sum=0;
	while(m>0)
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
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		ll x; 
		scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}
	scanf("%lld",&p);

	for(ll i=0;i<=n;i++)
	{
		sum[i]=sum[i]-i*p;
		ss[i]=sum[i];
	}
	
	sort(sum,sum+n+1);//ÀëÉ¢»¯ 
	ll len=unique(sum,sum+1+n)-sum;
	map<ll,ll>mp;
	for(ll i=0;i<len;i++)
	{
		mp[sum[i]]=i;
		c[i]=0;
	}
	maxm=len+10;

	ll ans=0;
	for(ll i=0;i<=n;i++)
	{
        ll t=mp[ss[i]]+1;  
		ans+=getsum(t);
		add(t,1);
    }
	printf("%lld\n",ans);
}
