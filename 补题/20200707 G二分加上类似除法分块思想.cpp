#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll n,k,m;
bool check(ll x)
{
	ll re=n,t=k;
	while(t>0&&re>0)
	{
		ll y=re/x;
		if(y>m)
		{
			ll a=re/y-x+1;
			re=re-min(t,a)*y;
			t-=(min(t,a));
		}
		else
		{
			re-=(t*m);
			t=0;
		}
	}
	return re<=0;
}

int main()
{
	scanf("%lld %lld %lld",&n,&k,&m);
	ll l=1,r=n;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%lld\n",l-1);
}
