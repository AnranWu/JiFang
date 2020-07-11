#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=5e4+50;
const ll maxm=5e4+50;
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
char s[50];
int main()
{
	ll t,Case=0;
	scanf("%lld",&t);
	while(t--)
	{
		memset(c,0,sizeof(c));
		ll n;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++)
		{
			ll x;
			scanf("%lld",&x);
			add(i,x);
		}
		ll a,b;
		printf("Case %lld:\n",++Case);
		while(scanf("%s",s)!=EOF&&s[0]!='E')
		{
			scanf("%lld %lld",&a,&b);
			if(s[0]=='Q')
			{
				printf("%lld\n",getsum(b)-getsum(a-1));
			}
			else if(s[0]=='A')
			{
				add(a,b);
			}
			else if(s[0]=='S')
			{
				add(a,-b);
			}
			else break;

		}
	}
}

