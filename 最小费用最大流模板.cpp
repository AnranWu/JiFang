#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct qy
{
	int x,y,flow,cost;
};

int n,m,S,T,i,j,x,y,z1,z2,tot,maxflow,mincost;
qy l[200005];
int next[200005],last[200005];
int dis[5005],flow[5005],from[5005],bz[5005];
int list[200005],head,tail;

void insert(int x,int y,int z1,int z2)
{
	tot++;
	l[tot].x=x;
	l[tot].y=y;
	l[tot].flow=z1;
	l[tot].cost=z2;
	next[tot]=last[x];
	last[x]=tot;
}

int spfa()
{
	memset(bz,0,sizeof(bz));
	memset(flow,0,sizeof(flow));
	memset(dis,120,sizeof(dis));
	list[1]=S;bz[S]=1;head=0;tail=1;dis[S]=0;flow[S]=1000000000;
	while (head<tail)
	{
		int x=list[++head];
		for (int i=last[x];i>=1;i=next[i])
		{
			int y=l[i].y;
			if ((l[i].flow>0)&&(dis[y]>dis[x]+l[i].cost))
			{
				dis[y]=dis[x]+l[i].cost;
				from[y]=i;
				flow[y]=min(flow[x],l[i].flow);
				if (!bz[y])
				{
					bz[y]=1;list[++tail]=y;
				}
			}
		}
		bz[x]=0;
	}
	if (flow[T]>0) return 1;
	else return 0;
}

void mfmc()
{
	while (spfa())
	{
		maxflow+=flow[T];
		mincost+=flow[T]*dis[T];
		for (int x=T;x!=S;x=l[from[x]].x)
		{
			l[from[x]].flow-=flow[T];
			l[from[x]^1].flow+=flow[T];
		}
	}
}

int main()
{
	freopen("read.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&S,&T);
	tot=1;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&z1,&z2);
		insert(x,y,z1,z2);
		insert(y,x,0,-z2);
	}
	mfmc();
	printf("%d %d",maxflow,mincost);
}
