#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
 
using namespace std;
 
const int MAX = (1ll << 31) - 1;
 
int read(){
    int x = 0; int zf = 1; char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
 
struct Edge{
    int to;
    int dis;
    int next;
} edges[210000];
 
int cur[10010], head[10010], edge_num = -1;
int n, m, s, t;

void addEdge2(int from, int to, int dis){
    edges[++edge_num].to = to;
    edges[edge_num].dis = dis;
    edges[edge_num].next = head[from];
    head[from] = edge_num;
}
 
void addEdge(int from, int to, int dis){
    addEdge2(from, to, dis), addEdge2(to, from, 0);
}
 
int d[10010];
 
int DFS(int u, int flow){
    if (u == t) return flow;
    int _flow = 0, __flow;
    for (int& c_e = cur[u]; c_e != -1; c_e = edges[c_e].next){
        int v = edges[c_e].to;
        if (d[v] == d[u] + 1 && edges[c_e].dis > 0){
            __flow = DFS(v, min(flow, edges[c_e].dis));
            flow -= __flow;
            edges[c_e].dis -= __flow;
            _flow += __flow;
            edges[c_e^1].dis += __flow;
            if (!flow)
                break;
        }
    }
    if (!_flow) d[u] = -1;
    return _flow;
}

bool BFS(){
    memset(d, -1, sizeof(d));
    queue<int> que; que.push(s);
    d[s] = 0; int u, _new;
    while (!que.empty()){
        u = que.front(), que.pop();
        for (int c_e = head[u]; c_e != -1; c_e = edges[c_e].next){
            _new = edges[c_e].to;
            if (d[_new] == -1 && edges[c_e].dis > 0){
                d[_new] = d[u] + 1;
                que.push(_new);
            }
        }
    }
    return (d[t] != -1);
}
int Case=1;
void dinic(){
    int max_flow = 0;
    while (BFS()){
        for (int i = 1; i <= n; ++i) cur[i] = head[i];
        max_flow += DFS(s, MAX);
    }
    
    printf("Case %d: %d\n",Case++ , max_flow);
}

void init()
{
	edge_num=-1;
}

int main(){
	int T=read();
	
	while(T--)
	{
		init();
		n = read(), m = read();s=1,t=n;
	    memset(head, -1, sizeof(head));
	    for (int i = 0; i < m; i++)
		{
	        int u = read(), v = read(), w = read();
	        addEdge(u, v, w);
	    }
	    dinic();
	}
	    
    return 0;
}
