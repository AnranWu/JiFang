#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=2e5+50;
const int INF=0x3f3f3f3f;

bool vis[maxn];
int dis,nx,ny,n;
int dx[maxn],dy[maxn],cx[maxn],cy[maxn];
int a[maxn],b[maxn],x[maxn],y[maxn];

struct Edge
{
	int to,nxt;
}e[maxn*2];

int head[maxn],ct=0;

void add(int u,int v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

bool bfs()
{
	queue<int>que;
	dis=INF;
	memset(dy,0,sizeof(dy));
	memset(dx,0,sizeof(dx));
	for(int i=1;i<=nx;i++)
	{
		if(!cx[i])que.push(i),dx[i]=1;
	}
	while(!que.empty())
	{
		int u=que.front();que.pop();
		if(dx[u]>dis)break;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(!dy[v])
			{
				dy[v]=dx[u]+1;
				if(!cy[v])dis=dy[v];
				else dx[cy[v]]=dy[v]+1,que.push(cy[v]);
			}
		}
	}
	return dis!=INF;
}

int dfs(int u)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(!vis[v]&&dy[v]==dx[u]+1)
		{
			vis[v]=1;
			if(cy[v]&&dy[v]==dis)continue;
			if(!cy[v]||dfs(cy[v]))
			{
				cy[v]=u;
				cx[u]=v;
				return 1;
			}
		}
	}
	return 0;
}

int hopcroft_karp()
{
	int ans=0;
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	while(bfs())
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=nx;i++)
		{
			if(!cx[i])ans+=dfs(i);
		}
	}
	return ans;
}

void init()
{
	memset(head,0,sizeof(head));
	ct=0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)
		{
			int xx,yy;
			scanf("%d %d",&xx,&yy);
			a[i]=yy+xx;
			b[i]=yy-xx;
			x[i]=yy+xx;
			y[i]=yy-xx;
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		nx=unique(a+1,a+1+n)-a-1;
		ny=unique(b+1,b+1+n)-b-1;
		for(int i=1;i<=n;i++)
		{
			int xid=lower_bound(a+1,a+1+nx,x[i])-a;
			int yid=lower_bound(b+1,b+1+ny,y[i])-b+nx;
			add(xid,yid);
		}
		printf("%d\n",hopcroft_karp());
	}
}
