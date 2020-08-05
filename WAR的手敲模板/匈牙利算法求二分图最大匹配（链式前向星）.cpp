#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e3+50;

ll n,m,match[1050];
bool vis[1050];
struct node
{
	ll to,nxt;
}e[50050];
ll head[1050],ct=0;
void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

bool dfs(ll u)
{
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(!vis[v])
		{
			vis[v]=1;
			if(match[v]==0||dfs(match[v]))
			{
				match[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	ll k;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=k;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		add(u,v);
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))ans++;
	}
	printf("%lld\n",ans);
}
/*
匈牙利算法模板(链式前向星） 
模板题链接：https://www.luogu.com.cn/problem/P3386
数据范围：1<=n,m<=500  k<=5e4 
*/
