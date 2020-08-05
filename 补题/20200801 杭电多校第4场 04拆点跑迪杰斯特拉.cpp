#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e6+50;
const ll inf=0x3f3f3f3f3f3f3f3f;

int n,m,s,t,x;
char str[maxn];
ll dis[maxn*2];
int flag[maxn*2];
struct node
{
    ll dis;
    int id;
    bool operator < (const node & a)const{
        return dis>a.dis;
    }
}now;

struct Edge
{
    int to,nxt;
    ll w;
}e[maxn*4];

int head[maxn],ct=0;
void add(int u,int v,ll w)
{
    e[++ct].to=v;
    e[ct].w=w;
    e[ct].nxt=head[u];
    head[u]=ct;
};

void dij()
{
    priority_queue<node>pq;
    if(str[s-1]=='M')
    {
        dis[s+n]=0;
        pq.push((node){0,s+n});
    }
    dis[s]=0;
    pq.push((node){0,s});
    while(!pq.empty())
    {
        now=pq.top();pq.pop();
        int u=now.id;
        if(now.dis>dis[u])continue;
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].to;
            int w=e[i].w;
            if(dis[v]>dis[u]+w)
            {    
                
                dis[v]=dis[u]+w;
                pq.push((node){dis[v],v});
            }
        }
    }
    
}

void init()
{
    ct=0;
    memset(head,0,sizeof(head));
    memset(dis,inf,sizeof(dis));
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&x);
        scanf("%s",str);
        for(int i=0;i<n;i++)
        {
            if(str[i]=='L')flag[i+1]=-1;
            else if(str[i]=='R')flag[i+1]=1;
            else flag[i+1]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int u,v;
            ll w;
            scanf("%d%d%lld",&u,&v,&w);
            if(flag[u]==-1&&flag[v]==-1)
            {
                add(u,v,w);
                add(v,u,w);
            }
            else if(flag[u]==-1&&flag[v]==1)
            {
                add(u,v,w+x);
                add(v,u,w+x);
            }
            else if(flag[u]==-1&&flag[v]==0)
            {
                add(u,v,w);
                add(v,u,w);
                add(u,v+n,w+x);
                add(v+n,u,w+x);
            }
            else if(flag[u]==1&&flag[v]==1)
            {
                add(u,v,w);
                add(v,u,w);
            }
            else if(flag[u]==1&&flag[v]==-1)
            {
                add(u,v,w+x);
                add(v,u,w+x);
            }
            else if(flag[u]==1&&flag[v]==0)
            {
                add(u,v,w+x);
                add(v,u,w+x);
                add(u,v+n,w);
                add(v+n,u,w);
            }
            else if(flag[u]==0&&flag[v]==0)
            {
                add(u,v,w);
                add(v,u,w);
                add(u,v+n,w+x);
                add(v+n,u,w+x);
                add(u+n,v,w+x);
                add(v,u+n,w+x);
                add(u+n,v+n,w);
                add(v+n,u+n,w);
            }
            else if(flag[u]==0&&flag[v]==-1)
            {
                add(v,u,w);
                add(u,v,w);
                add(v,u+n,w+x);
                add(u+n,v,w+x);
            }
            else 
            {
                add(v,u,w+x);
                add(u,v,w+x);
                add(v,u+n,w);
                add(u+n,v,w);
            }
        }
        dij();
        printf("%lld\n",min(dis[t],dis[t+n]));
    }
    return 0;
}
