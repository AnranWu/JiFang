#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

ll a[maxn];
struct node
{
	ll to,nxt;
}e[maxn];

ll head[maxn],ct=0;

void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}
ll dp[1050][1050];
int main()
{
	ll n,m,c;
	scanf("%lld %lld %lld",&n,&m,&c);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		add(v,u);
	}
	ll ans=0;
	memset(dp,-1,sizeof(dp));
	dp[0][1]=0;
	for(ll i=1;i<=1000;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll k=head[j];k;k=e[k].nxt)
			{
				ll to=e[k].to;
				if(dp[i-1][to]>=0)
				dp[i][j]=max(dp[i][j],dp[i-1][to]+a[j]);
			}
		}
		if(ans<f[i][1]-C*i*i) ans=f[i][1]-C*i*i;
		ans=max(ans,dp[i][1]-c*i*i);
	}
	printf("%lld\n",ans);
	return 0;
}
