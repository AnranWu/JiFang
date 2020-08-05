#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e3+50;

ll n,m,match[1050];
bool vis[1050];
bool mp[1050][1050];

bool dfs(ll u)
{
	for(ll i=1;i<=m;i++)
	{
		if(mp[u][i]&&!vis[i])
		{
			vis[i]=1;
			if(match[i]==0||dfs(match[i]))
			{
				match[i]=u;
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
		mp[u][v]=1;

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
匈牙利算法模板
模板题链接：https://www.luogu.com.cn/problem/P3386
数据范围：1<=n,m<=500  k<=5e4 
*/
