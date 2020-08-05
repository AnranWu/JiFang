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
	e[ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
	ct++;
}

ll dfn[maxn],low[maxn],cnt,sta[maxn],top=0;
ll rd[maxn],bcc[maxn],bccnum=0;

bool ef[maxn],isCut[maxn],vis[maxn];

void tarjan(ll u)
{
	dfn[u]=low[u]=++cnt;
	sta[++top]=u;
	for(ll i=head[u];i!=-1;i=e[i].nxt)
	{
		ll to=e[i].to;
		if(ef[i])continue;
		ef[i]=1;
		ef[i^1]=1;
		if(!dfn[to])
		{
			tarjan(to);
			low[u]=min(low[u],low[to]);
			if(low[to]>dfn[u])isCut[i]=1,isCut[i^1]=1;
		}
		else low[u]=min(low[u],dfn[to]);
	}
}

void dfs(ll u)
{
	vis[u]=1;
	bcc[u]=bccnum;
	for(ll i=head[u];i!=-1;i=e[i].nxt)
	{
		ll to=e[i].to;
		if(!vis[to]&&!isCut[i])dfs(to);
	}
}

int main()
{
	ll n,m;
	memset(head,-1,sizeof(head));
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(ll i=1;i<=n;i++)if(!dfn[i])tarjan(i);
		
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bccnum++;
			dfs(i);
		}
	}
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=head[i];j!=-1;j=e[j].nxt)
		{
			ll to=e[j].to;
			if(bcc[to]!=bcc[i])
			{
				rd[bcc[to]]++;
			}
		}
	}
	ll ans=0;
	for(ll i=1;i<=bccnum;i++)
	{
		if(rd[i]==1)ans++;
	}
	
	printf("%lld\n",(ans+1)/2);
}
