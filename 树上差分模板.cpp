#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
#include<fstream>
#include<vector>
#include<stack>
#include <map>
#include <iomanip> 
#define bug cout << "**********" << endl
#define out cout<<"---------------"<<endl
#define show(x, y) "["<<x<<","<<y<<"] "
//#define LOCAL = 1;
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = 1e8;
const int Max = 5e4 + 10;
const int Max2 = 5e3 + 10;
 
struct Edge
{
	int to, next;
}edge[Max<<1];
 
int n, k;
int head[Max], tot;
 
int lg[Max];				//log2 n 向下取整
int father[Max][25];		//倍增法求祖先
int deep[Max];				//记录深度
int val[Max];				//记录差分数组
int max_val;
 
 
void add(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
 
void dfs(int now, int fa, int depth)
{
	deep[now] = depth;
	father[now][0] = fa;
 
	for (int i = 1;i <= 20;i++)
		father[now][i] = father[father[now][i - 1]][i - 1];
 
	for (int i = head[now]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v != fa)
			dfs(v, now, depth + 1);
	}
}
 
int lca(int a, int b)
{
	if (deep[a] < deep[b]) swap(a, b);
 
	while (deep[a] != deep[b])
	{
		a = father[a][lg[deep[a] - deep[b]]];
	}
 
	/*for (int i = 20; i >= 0; i--)
		if (deep[father[a][i]] >= deep[b])
			a = father[a][i];*/
 
	if (a == b) return a;
 
	for (int i = 20; i >= 0;i--)
	{
		if (father[a][i] != father[b][i])
		{
			a = father[a][i];
			b = father[b][i];
		}
	}
	return father[a][0];
}
 
 
void insert(int s, int e)		//差分核心所在
{
	val[s]++;val[e]++;			//起止均加上权值
	int Lca = lca(s, e);
	val[Lca]--;val[father[Lca][0]]--;
}
 
void sum(int now)				//求差分数组的和
{
	for (int i = head[now]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v != father[now][0])
		{
			sum(v);
			val[now] += val[v];
		}
	}
	max_val = max(max_val, val[now]);
}
 
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	lg[0] = -1;
	for (int i = 1;i < Max;i++)
		lg[i] = 1 + lg[i >> 1];
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(head, -1, sizeof(head));tot = 0;
		memset(val, 0, sizeof(val));max_val = 0;
 
		for(int i = 1,u,v;i < n ;i ++)
		{
			scanf("%d%d", &u, &v);
			add(u, v);add(v, u);
		}
		dfs(1,0,1);			//根结点之上可能还有结点被标记
 
 
		for(int i = 1,u,v ;i <= k ;i ++)
		{
			scanf("%d%d", &u, &v);
			insert(u, v);
		}
		add(0, 1);
		sum(0);
		printf("%d\n", max_val);
	}
 
	return 0;
}

