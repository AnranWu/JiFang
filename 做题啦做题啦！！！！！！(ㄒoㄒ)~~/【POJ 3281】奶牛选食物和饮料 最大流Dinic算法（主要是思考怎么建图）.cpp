#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 10005
#define maxm 200005
#define inf 2147483647

struct edge {
    int v,  c, next;
}edges[maxm];
int n, m;
int tail = 1;
int head[maxn];
int depth[maxn];
int s, t;
void add_edge(int u, int v, int c) {
    edges[tail].next=head[u];
    head[u]=tail;
    edges[tail].v=v;
    edges[tail++].c=c;
} inline int bfs() {
    int queue[maxn];
    int front=0; int back=1;
    queue[front]=s; int u;
    memset(depth, 0, sizeof(depth));
    depth[s]=1; queue[0]=s;
    while (front<back) {
        u=queue[front++];
        for (int i = head[u]; i; i=edges[i].next) {
            if (edges[i].c>0&&depth[edges[i].v]==0) {
                depth[edges[i].v]=depth[u]+1;
                queue[back++]=edges[i].v;
            }
        }
    } if (depth[t]==0) return 0;
    return 1;
} int dfs(int u, int f) {
    if (u==t) return f;
    for (int i = head[u]; i; i=edges[i].next) {
        if (depth[edges[i].v]==depth[u]+1&&edges[i].c!=0) {
            int d = dfs(edges[i].v, min(f, edges[i].c));
            if (d>0) {
                edges[i].c-=d;
                edges[((i-1)^1)+1].c+=d;
                return d;
            }
        }
    } return 0;
}int Dinic() {
    int ans = 0; int d;
    while (bfs()) {
        while (d=dfs(s, inf)) {
            ans+=d;
        }
    }return ans;
} 
int main() {
    int a, b, c;
    
    int N,F,D;
	scanf("%d %d %d",&N,&F,&D);
	for(int i=1;i<=N;i++)
	{
		add_edge(i,i+100,1);
		add_edge(i+100,i,0);
	}
	for(int i=1;i<=F;i++)
	{
		add_edge(0,200+i,1);
		add_edge(200+i,0,0);
	}
	for(int i=1;i<=D;i++)
	{
		add_edge(300+i,401,1);
		add_edge(401,300+i,0);
	}
	for(int i=1;i<=N;i++)
	{
		int fi,di,x;
		scanf("%d %d",&fi,&di);
		for(int j=1;j<=fi;j++)
		{
			scanf("%d",&x);
			add_edge(200+x, i, 1);
			add_edge(i, 200+x, 0);
		}
		for(int j=1;j<=di;j++)
		{
			scanf("%d",&x);
			add_edge(100+i, 300+x, 1);
			add_edge(300+x, 100+i, 0);
		}
	}
    n=401,s=0,t=401;
    printf("%d\n", Dinic());
    return 0;
}
