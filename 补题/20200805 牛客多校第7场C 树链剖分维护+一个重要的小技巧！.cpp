/****************************
* Author : W.A.R            *
* Date : 2020-08-05-21:31   *
****************************/
/*
树链剖分初始化需要初始化head数组、son数组、ct和cnt。
给定一个点x，让整棵树所有节点（包括x）y的点权都加上deep[lca(x,y)],可以转化为在根结点到结点x上所有的边权加1，最后询问点权
时只需要询问从根结点到当前询问结点的边权和即可。
*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<string>
#pragma warning(disable:4996)
using namespace std;
typedef int ll;
const int maxn = 2e5 + 50;
const ll mod = 1e9 + 7;
int n, m, op, a, b, ssum = 0, num = 0,val[maxn];

ll cnt = 0, top[maxn], siz[maxn], id[maxn], rk[maxn], fa[maxn], dep[maxn], son[maxn];

ll head[maxn], ct = 0;

struct node
{
	ll to, nxt;
}e[maxn*2];

void add(ll u, ll v)
{
	e[++ct].to = v;
	e[ct].nxt = head[u];
	head[u] = ct;
}

struct nnode
{
	ll l, r, sum, lazy;
}tree[maxn * 4];

void dfs1(ll u)
{
	if(u==1)dep[u]=0;
	else dep[u] = dep[fa[u]] + 1;
	siz[u] = 1; 
	for (ll i = head[u]; i; i = e[i].nxt)
	{
		ll v = e[i].to;
		if (v != fa[u])
		{
			fa[v] = u;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v]>siz[son[u]])son[u] = v;
		}
	}
}

void dfs2(ll u, ll tou)
{
	top[u] = tou;
	id[u] = ++cnt;
	rk[cnt] = u;
	if (son[u])dfs2(son[u], tou);
	for (ll i = head[u]; i; i = e[i].nxt)
	{
		ll v = e[i].to;
		if (v != fa[u] && v != son[u])
		{
			dfs2(v, v);
		}
	}
}

ll len(ll rt)
{
	return tree[rt].r - tree[rt].l + 1;
}

void pushup(ll rt)
{
	tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) ;
}

void pushdown(ll rt)
{
	if (tree[rt].lazy)
	{
		tree[rt << 1].sum = (tree[rt << 1].sum + len(rt << 1)*tree[rt].lazy);
		tree[rt << 1].lazy += tree[rt].lazy;
		tree[rt << 1 | 1].sum = (tree[rt << 1 | 1].sum + len(rt << 1 | 1)*tree[rt].lazy);
		tree[rt << 1 | 1].lazy += tree[rt].lazy;
		tree[rt].lazy = 0;
	}
}

void build(ll rt, ll l, ll r)
{tree[rt].sum = 0;
		tree[rt].lazy=0;
	if (l == r)
	{
		
		tree[rt].l = tree[rt].r = l;
		return;
	}
	ll mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	tree[rt].l = l; tree[rt].r = r;
	pushup(rt);
}

void update(ll rt, ll l, ll r, ll w)
{
	if (tree[rt].l >= l&&tree[rt].r <= r)
	{
		tree[rt].lazy = (tree[rt].lazy + w);
		tree[rt].sum = (tree[rt].sum + len(rt)*w) ;
		return;
	}
	pushdown(rt);
	ll mid = tree[rt].l + tree[rt].r >> 1;
	if (mid >= l)update(rt << 1, l, r, w);
	if (mid<r)update(rt << 1 | 1, l, r, w);
	pushup(rt);
}

ll query(ll rt, ll l, ll r)
{
	if (tree[rt].l >= l&&tree[rt].r <= r)return tree[rt].sum;
	pushdown(rt);
	ll mid = tree[rt].l + tree[rt].r >> 1;
	ll ans = 0;
	if (mid >= l)ans += query(rt << 1, l, r);
	if (mid<r)ans += query(rt << 1 | 1, l, r);
	return ans;
}

ll sum(ll x, ll y)
{
	ll ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]]<dep[top[y]])swap(x, y);
		ans = (ans + query(1, id[top[x]], id[x])) ;
		x = fa[top[x]];
	}
	if (id[x]>id[y])swap(x, y);
	ans = (ans + query(1, id[x], id[y])) ;
	return ans;
}

void updates(ll x, ll y, ll z)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]]<dep[top[y]])swap(x, y);
		update(1, id[top[x]], id[x], z);
		x = fa[top[x]];
	}
	if (id[x]>id[y])swap(x, y);
	update(1, id[x], id[y], z);
}

void init() {
	ct = 0;
	cnt=0;
	memset(son,0,sizeof(head));
	memset(head,0,sizeof(head));
	memset(val,0,sizeof(val));
	ssum=0;
	num=0;
}

void work() {
	
	scanf("%d%d", &n,&m);
	init();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	int root = 1;
	dfs1(root);
	dfs2(root, root);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &a, &b);
			ssum += (b - dep[a]);
			num++;
			updates(1, a, 2);
		}
		else if (op == 2) {
			scanf("%d", &a);
			int ans = val[a] + ssum - dep[a] * num + sum(1, a) - num * 2;
			if (ans > 0)val[a] -= ans;

		}
		else {
			scanf("%d", &a);
			int ans = val[a] + ssum - dep[a] * num + sum(1, a) - num * 2;
			printf("%d\n", ans);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		work();
	}
	//system("pause");
	return 0;
}
