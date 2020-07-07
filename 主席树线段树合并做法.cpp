#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100010;
struct seg_tree{
    int val, lson, rson;
}st[N * 100];
int len, rt[N];
struct node{
    int pre, to;
}edge[2 * N];
int head[N], tot;
int n, m;
int t[N];
int depth[N], f[N][25];
int lca(int x, int y) 
{
    if (depth[x] < depth[y]) swap(x, y);
    int d = depth[x] - depth[y];
    for (int i = 0; i <= 20; i++) 
	{
        if ((1 << i) & d) 
		{
            x = f[x][i];
            d -= (1 << i);
        }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) 
	{
        if (f[x][i] != f[y][i]) 
		{
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}
void ad(int u, int v) 
{
    edge[++tot] = node{head[u], v};
    head[u] = tot;
}
void add(int &x, int l, int r, int v) 
{
    if (!x) x = ++len;
    if (l == r) {
        st[x].val++;
        return;
    }
    int mid = (l + r) >> 1;
    if (v <= mid) add(st[x].lson, l, mid, v);
    else add(st[x].rson, mid + 1, r, v);
    st[x].val = st[st[x].lson].val + st[st[x].rson].val;
}
int merge(int u, int v) 
{
    if (!u) return v;
    if (!v) return u;
    st[u].val += st[v].val;
    st[u].lson = merge(st[u].lson, st[v].lson);
    st[u].rson = merge(st[u].rson, st[v].rson);
    return u;
}
void dfs(int x, int fa) 
{
    for (int i = 1; i <= 20; i++) 
	{
        f[x][i] = f[f[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i; i = edge[i].pre) 
	{
        int y = edge[i].to;
        if (y == fa) continue;
        f[y][0] = x;
        depth[y] = depth[x] + 1; 
        rt[y] = merge(rt[y], rt[x]);
        dfs(y, x);
    }
}
int ask(int x, int l, int r, int p) 
{
    if (!x) return 0;
    if (l == r) return st[x].val;
    int mid = (l + r) >> 1;
    if (p <= mid) return ask(st[x].lson, l, mid, p);
    else return ask(st[x].rson, mid + 1, r, p);
}
int main() 
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
	{
        cin >> t[i];
        add(rt[i], 1, n, t[i]);
    }
    for (int i = 1, a, b; i < n; i++) 
	{
        cin >> a >> b;
        ad(a, b);
        ad(b, a);
    }
    dfs(1, 0);
    for (int i = 1, a, b, c; i <= m; i++) 
	{
        cin >> a >> b >> c;
        int LCA = lca(a, b);
        if (ask(rt[a], 1, n, c) + ask(rt[b], 1, n, c) - ask(rt[LCA], 1, n, c) - ask(rt[f[LCA][0]], 1, n, c) > 0) cout << 1;
        else cout << 0;
    }
    return 0; 
}
