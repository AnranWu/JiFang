/****************************
* Author : W.A.R            *
* Date : 2020-08-05-15:24   *
****************************/
/*
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
const int maxn = 1e6 + 50;
const ll mod = 1e9 + 7;
int n, m, op, a, b, ssum = 0, num = 0,val[maxn];

namespace Fast_IO
{ //orz laofu
	const int MAXL((1 << 18) + 1); int iof, iotp;
	char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL], *iooS = ioof, *iooT = ioof + MAXL - 1, ioc, iost[55];
	char Getchar() {
		if (ioiS == ioiT) {
			ioiS = ioif; ioiT = ioiS + fread(ioif, 1, MAXL, stdin); return (ioiS == ioiT ? EOF : *ioiS++);
		}
		else return (*ioiS++);
	}
	void Write() { fwrite(ioof, 1, iooS - ioof, stdout); iooS = ioof; }
	void Putchar(char x) { *iooS++ = x; if (iooS == iooT)Write(); }
	inline int read() {
		int x = 0; for (iof = 1, ioc = Getchar(); (ioc<'0' || ioc>'9') && ioc != EOF;)iof = ioc == '-' ? -1 : 1, ioc = Getchar();
		if (ioc == EOF)exit(0);
		for (x = 0; ioc <= '9'&&ioc >= '0'; ioc = Getchar())x = (x << 3) + (x << 1) + (ioc ^ 48); return x*iof;
	}
	inline long long read_ll() {
		long long x = 0; for (iof = 1, ioc = Getchar(); (ioc<'0' || ioc>'9') && ioc != EOF;)iof = ioc == '-' ? -1 : 1, ioc = Getchar();
		if (ioc == EOF)exit(0);
		for (x = 0; ioc <= '9'&&ioc >= '0'; ioc = Getchar())x = (x << 3) + (x << 1) + (ioc ^ 48); return x*iof;
	}
	template <class Int>void Print(Int x, char ch = '\0') {
		if (!x)Putchar('0'); if (x < 0)Putchar('-'), x = -x; while (x)iost[++iotp] = x % 10 + '0', x /= 10;
		while (iotp)Putchar(iost[iotp--]); if (ch)Putchar(ch);
	}
	void Getstr(char *s, int &l) {
		for (ioc = Getchar(); ioc == ' ' || ioc == '\n' || ioc == '\t';)ioc = Getchar();
		if (ioc == EOF)exit(0);
		for (l = 0; !(ioc == ' ' || ioc == '\n' || ioc == '\t' || ioc == EOF); ioc = Getchar())s[l++] = ioc; s[l] = 0;
	}
	void Putstr(const char *s) { for (int i = 0, n = strlen(s); i < n; ++i)Putchar(s[i]); }
} // namespace Fast_IO 
using namespace Fast_IO;

ll cnt = 0, top[maxn], siz[maxn], id[maxn], rk[maxn], fa[maxn], dep[maxn], son[maxn];

ll head[maxn], ct = 0;

struct node
{
	ll to, nxt;
}e[maxn];

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
	siz[u] = 1; dep[u] = dep[fa[u]] + 1;
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
	tree[rt].sum = (tree[rt << 1].sum + tree[rt << 1 | 1].sum) % mod;
}

void pushdown(ll rt)
{
	if (tree[rt].lazy)
	{
		tree[rt << 1].sum = (tree[rt << 1].sum + len(rt << 1)*tree[rt].lazy) % mod;
		tree[rt << 1].lazy += tree[rt].lazy;
		tree[rt << 1 | 1].sum = (tree[rt << 1 | 1].sum + len(rt << 1 | 1)*tree[rt].lazy) % mod;
		tree[rt << 1 | 1].lazy += tree[rt].lazy;
		tree[rt].lazy = 0;
	}
}

void build(ll rt, ll l, ll r)
{
	if (l == r)
	{
		tree[rt].sum = 0;
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
		tree[rt].lazy = (tree[rt].lazy + w) % mod;
		tree[rt].sum = (tree[rt].sum + len(rt)*w) % mod;
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
	return ans%mod;
}

ll sum(ll x, ll y)
{
	ll ans = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]]<dep[top[y]])swap(x, y);
		ans = (ans + query(1, id[top[x]], id[x])) % mod;
		x = fa[top[x]];
	}
	if (id[x]>id[y])swap(x, y);
	ans = (ans + query(1, id[x], id[y])) % mod;
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
	fa[1] = 0;
	dep[0] = -1;
	for (int i = 0; i <= n; i++) {
		head[i] = 0;
		val[i] = 0;
	}
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
	dfs2(root, root); printf("1111111\n");
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
	system("pause");
	return 0;
}