#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1050;

struct node
{
	ll a,b,c;
}a[maxn];

ll n,m,k;
bool vis[maxn];
ll mp[1050][1050];
ll match[maxn];
//邻接矩阵建图
bool dfs(int u)
{
    for(int v=1;v<=n;v++)
    {
    	if(mp[u][v]&&!vis[v])
		{
            vis[v]=true;
            if( match[v] ==-1 ||dfs(match[v])) 
			{
	            match[v]=u;
	            return true;
        	}
    	}
	}  
    return false;
}

int main()
{
	while(scanf("%lld",&n)!=EOF&&n)
	{
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld %lld %lld",&a[i].a,&a[i].b,&a[i].c);
		}
		memset(mp,0,sizeof(mp));
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(a[i].a<a[j].a&&a[i].b<a[j].b&&a[i].c<a[j].c)
				{
					mp[i][j]=1;
				}
			}
		}
		int sum = 0;//匹配数
		
		memset(match,-1,sizeof(match));//Y部结点匹配的X部结点的编号
		for (int i=1; i<=n; i++)
		{
		    memset(vis,0,sizeof(vis));
		    if (dfs(i)) sum++;
		}
		printf("%d\n",n-sum);
	}
}
