#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

struct nnode
{
	ll to,nxt;
}e[maxn];
ll head[maxn],ct=0;ll n,m;
bool vis[maxn];
void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

struct node
{
	ll v,id;
}a[maxn];

bool cmp(node a,node b)
{
	return a.v>b.v;
}

ll father[maxn];
ll find(ll x)//ÕÒ¸¸Ç×
{
	return x==father[x]?x:father[x]=find(father[x]);
}

void merge(ll x,ll y)//ºÏ²¢ 
{
	father[x]=y;
}

void init()
{
	ct=0;
	for(ll i=0;i<=n;i++)
	{
		head[i]=0;
		vis[i]=0;
		
	}
}
int main()
{
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&m);
		init();
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].v);
			father[i]=i;
			a[i].id=i;
		}
		for(ll i=1;i<=m;i++)
		{
			ll u,v;
			scanf("%lld %lld",&u,&v);
			add(u,v);
			add(v,u);
		}
		sort(a+1,a+1+n,cmp);
		ll now=a[1].v;
		ll sum=0,ans=0;
		for(ll i=1;i<=n;i++)
		{
			ll u=a[i].id;
			ans+=(sum*(now-a[i].v));
			sum++;
			vis[u]=1;
			for(ll j=head[u];j;j=e[j].nxt)
			{
				ll v=e[j].to;
				if(vis[v])
				{
					ll x=find(u);
					ll y=find(v); 
					if(x!=y)
					{
						merge(x,y);
						sum--;
					}
					
				}
			}
			now=a[i].v;
		}
		ans+=(sum*now);
		printf("%lld\n",ans);
	}
}
