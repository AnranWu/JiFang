#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll top=0,sta[maxn],ans=0,head[maxn],vis[maxn],cnt,ct,dfn[maxn],low[maxn];
struct node
{
	ll to,nxt;
}e[maxn];

void add(ll u,ll v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}




void tarjan(ll u)
{
	dfn[u]=low[u]=++ct;
	sta[++top]=u;
	vis[u]=1;
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		ll cur,num=0;
		while(top)
		{
			cur=sta[top--];
			vis[cur]=0;
			num++;
			if(cur==u)break;
		}
		if(num>1)ans++;
	}
}

int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		add(a,b);
	}
	for(ll i=1;i<=n;i++)
	{
		if(!dfn[i])tarjan(i);
	}
	printf("%lld\n",ans);
}
