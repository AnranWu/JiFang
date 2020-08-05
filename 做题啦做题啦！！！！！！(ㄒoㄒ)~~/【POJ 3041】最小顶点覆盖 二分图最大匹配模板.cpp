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

ll n,m;
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
	scanf("%d %d",&n,&m);
	for(ll i=1;i<=m;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		mp[u][v]=1;
	}
	int sum = 0;//匹配数
	memset(match,-1,sizeof(match));//Y部结点匹配的X部结点的编号
	for (int i=1; i<=n; i++)
	{
	    memset(vis,0,sizeof(vis));
	    if (dfs(i)) sum++;
	}
	printf("%d\n",sum);
}
