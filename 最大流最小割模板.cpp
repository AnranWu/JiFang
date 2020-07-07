#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 120050;
const int maxv = 200005;
const int INF = 0x3f3f3f3f;
int head[maxn], cur[maxn], d[maxn], n, m, s, t, k, sum;
struct node
{
    int v, w, next;
}edge[3000005];
void addEdge(int u, int v, int w)
{
    edge[k].v = v;
    edge[k].w = w;
    edge[k].next = head[u];
    head[u] = k++;
    edge[k].v = u;
    edge[k].w = 0;
    edge[k].next = head[v];
    head[v] = k++;
 
}
int bfs()
{
    memset(d, 0, sizeof(d));
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        if(u == t) return 1;
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int to = edge[i].v, w = edge[i].w;
            if(w && d[to] == 0)
            {
                d[to] = d[u] + 1;
                if(to == t) return 1;
                q.push(to);
            }
        }
    }
    return 0;
}
int dfs(int u, int maxflow)
{
    if(u == t) return maxflow;
    int ret = 0;
    for(int i = cur[u]; i != -1; i = edge[i].next)
    {
        int to = edge[i].v, w = edge[i].w;
        if(w && d[to] == d[u]+1)
        {
            int f = dfs(to, min(maxflow-ret, w));
            edge[i].w -= f;
            edge[i^1].w += f;
            ret += f;
            if(ret == maxflow) return ret;
        }
    }
    return ret;
}
int Dinic()
{
    int ans = 0;
    while(bfs())
    {
        memcpy(cur, head, sizeof(head));
        ans += dfs(s, INF);
    }
    return ans;
}
int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        s = 0, t = n+1, k = 0;
        memset(head, -1, sizeof(head));
        int x, y, z;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            addEdge(s, i, x);
            addEdge(i, t, y);
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            addEdge(x, y, z);
            addEdge(y, x, z);
        }
        printf("%d\n", Dinic());
    }
    return 0;
}

