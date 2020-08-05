/*
时间复杂度为sqrt(V)*E 
*/ 
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
int dis,nx,ny,k;
int dx[maxn],dy[maxn],cx[maxn],cy[maxn];
int a[maxn],x[maxn],y[maxn];

struct Edge
{
	int to,nxt;
}e[maxn*2];

int head[maxn],ct=0,cnt=0;

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
	cnt=0;
}

int main()
{
	int T,Case=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&nx);
		init();
		for(int i=1;i<=nx;i++)
		{
			int xx,yy;
			scanf("%d %d",&xx,&yy);
			x[i]=xx;
			y[i]=yy;
			a[++cnt]=xx;
			a[++cnt]=yy;
		}
		sort(a+1,a+1+cnt);
		ny=unique(a+1,a+1+cnt)-a-1;
		for(int i=1;i<=nx;i++)
		{
			int xid=lower_bound(a+1,a+1+ny,x[i])-a;
			int yid=lower_bound(a+1,a+1+ny,y[i])-a;
			add(i,xid);
			add(i,yid);
		}
		printf("Case #%d: %d\n",Case++,hopcroft_karp());
	}
}
