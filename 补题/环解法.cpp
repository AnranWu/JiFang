#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

ll n,m,k,zz;
ll huan[maxn],ct=0,to[maxn],ans[maxn],t[maxn];
bool vis[maxn];
void dfs(ll u)
{
	vis[u]=1;
	huan[ct++]=u;
	if(!vis[to[u]])dfs(to[u]);
	vis[u]=0;
}

void daan(ll x,ll st)
{
	vis[x]=1;
	ll tt=(st+zz)%ct;
	ans[x]=huan[tt];
	if(!vis[to[x]])daan(to[x],st+1);
}

int main()
{
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=n;i++)ans[i]=i,t[i]=i;
	for(ll i=1;i<=m;i++)
	{
		ll a,b;
		scanf("%lld %lld",&a,&b);
		for(ll j=a,l=b;j<l;j++,l--)
		{
			swap(t[j],t[l]);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		printf("%lld\n",t[i]);
		to[t[i]]=i;
	}
	for(zz=1;zz<=k;zz++)
	{
		memset(vis,0,sizeof(vis));
		for(ll i=1;i<=n;i++)
		{
			ct=0;
			if(!vis[i])
			{
				dfs(i);
				daan(i,0);
			}
		}
		for(ll i=1;i<=n;i++)printf("%lld\n",ans[i]);
		putchar(10);
	}
		
	
}



