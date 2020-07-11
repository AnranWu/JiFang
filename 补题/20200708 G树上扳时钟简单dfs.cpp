#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

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
ll a[maxn],b[maxn];
void dfs(ll u,ll fa)
{
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if(to==fa)continue;
		dfs(to,u);
		a[u]=(a[u]-a[to]+12)%12;
	}
}


int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	
	for(ll i=1;i<n;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		
		for(ll j=1;j<=n;j++)a[j]=b[j];
		dfs(i,0);
		if(a[i]==0||a[i]==1)ans++;
	}
	printf("%lld\n",ans);
}
