#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
 
using namespace std;
const int MAXN = 5500;
int n,m,w;
 
struct Edge
{
    int v,w,next;
}edge[MAXN];
int head[MAXN],dis[MAXN],vis[MAXN],t;
 
void Init()
{
    memset(head,-1,sizeof(head));
    t = 0;
}
void Add_edge(int u,int v,int w)
{
    edge[t].v = v;edge[t].w = w;edge[t].next = head[u];head[u] = t++;
}
 
bool SPFA()
{
    int mark[MAXN];//记录每个点如队列的次数
    for(int i = 1;i <= n;i ++)
    {
        mark[i] = 0;dis[i] = INF;vis[i] = 0;
    }
    queue<int> q;
    q.push(1);  //我们只需要判断负环，随便找一个起点就好
    dis[1] = 0;
    vis[1] = 1;//入队列
    mark[1] ++;
    while(!q.empty())
    {
        int  u = q.front();
        q.pop();
        vis[u] = 0;//出队列
        for(int i = head[u];i != -1;i = edge[i].next)
        {
            int v = edge[i].v;
            if(dis[v] > dis[u] + edge[i].w)
            {
                dis[v] = dis[u] + edge[i].w;
                if(!vis[v])//不在队列中的时候出队
                {
                    q.push(v);mark[v] ++;vis[v] = 1;
                }
                if(mark[v] >= n)//如果不存在负环，那么最多更新n-1次就可以得到最终的答案，因为一次最少更新一个节点，那么如果出现了更新n次，那么就一定出现了负环
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Init();
        int u,v,z;
        scanf("%d%d%d",&n,&m,&w);
        for(int i = 0;i < m;i ++)
        {
            scanf("%d%d%d",&u,&v,&z);
            Add_edge(u,v,z);
            Add_edge(v,u,z);
        }
        for(int i = 0;i < w;i ++)
        {
            scanf("%d%d%d",&u,&v,&z);
            Add_edge(u,v,-z);
        }
        if(!SPFA())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

