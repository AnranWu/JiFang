#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll ans1,ans2,cc;

struct node
{
	ll to,nxt;
}e[maxn];

ll head[maxn],ct;

void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

ll dfn[maxn],low[maxn],cnt,sta[maxn],top,a[maxn];
bool vis[maxn];

void tarjan(ll u,ll fa)
{
	dfn[u]=low[u]=++cnt;
	sta[++top]=u;
	for(ll i=head[u];i!=-1;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v==fa)continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])ans1++;
			if(low[v]>=dfn[u])
			{
				cc=0;
				ll x;
				memset(vis,0,sizeof(vis));
				do
				{
					x=sta[top--];
					vis[x]=1;
					a[cc++]=x;
				}
				while(x!=v);
				a[cc++]=u;
				vis[u]=1;
				ll sum=0;
				for(ll j=0;j<cc;j++)
				{
					ll uu=a[j];
					for(ll k=head[uu];k!=-1;k=e[k].nxt)
					{
						ll tt=e[k].to;
						if(vis[tt])sum++;
					}
				}
				sum/=2;
				if(sum>cc)ans2+=sum;
			}
		}
		else
		{
			low[u]=min(low[u],dfn[v]);
		}
	}
}

void init(ll n)
{
	ans1=0;
	ans2=0;
	cc=0;
	ct=0;
	cnt=0;
	top=0;
	for(ll i=0;i<=n;i++)
	{
		head[i]=-1;
		dfn[i]=0;
		low[i]=0;
		sta[i]=0;
		vis[i]=0;
	}
}

int main()
{
	ll n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF&&(n||m))
	{
		init(n);
		for(ll i=1;i<=m;i++)
		{
			ll u,v;
			scanf("%lld %lld",&u,&v);
			add(u,v);
			add(v,u);
		}
		for(ll i=0;i<n;i++)
		{
			if(!dfn[i])tarjan(i,-1);
		}
		printf("%lld %lld\n",ans1,ans2);
	}
		
}
