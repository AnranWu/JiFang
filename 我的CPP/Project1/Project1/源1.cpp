//#pragma warning(disable:4996)
//#include <iostream>
//#include <cstdio>
//#define ll long long
//using namespace std;
//const int N = 1e5 + 5;
//const int M = 1e5 + 5;
//struct Edge {
//	int to, next;
//}e[M << 1];
//int head[N], tot;
//void add(int u, int v) {
//	e[++tot].to = v;
//	e[tot].next = head[u];
//	head[u] = tot;
//}
//int depth[N], fa[N], son[N], siz[N];
//void dfs1(int now, int fath) {
//	fa[now] = fath, depth[now] = depth[fath] + 1;
//	siz[now] = 1;
//	for (int i = head[now]; i; i = e[i].next) {
//		int v = e[i].to;
//		if (v != fath) {
//			dfs1(v, now);
//			siz[now] += siz[v];
//			if (siz[v] > siz[son[now]]) son[now] = v;
//		}
//	}
//}
//ll val[N];
//int dfn[N], cnt, top[N];
//void dfs2(int u, int rt) {
//	dfn[u] = ++cnt;
//	top[u] = rt;
//	if (son[u]) dfs2(son[u], rt);
//	for (int i = head[u]; i; i = e[i].next) {
//		int v = e[i].to;
//		if (v != fa[u] && v != son[u]) dfs2(v, v);
//	}
//}
//struct Tree {
//	int l, r;
//	ll lazy, sum;
//#define l(p) tree[p].l
//#define r(p) tree[p].r
//#define sum(p) tree[p].sum
//#define lson(p) p << 1
//#define rson(p) p << 1 | 1
//#define lazy(p) tree[p].lazy
//}tree[N << 2];
//void build(int p, int l, int r) {
//	l(p) = l, r(p) = r;
//	sum(p) = lazy(p) = 0;
//	if (l == r) return;
//	int mid = (l + r) >> 1;
//	build(lson(p), l, mid); build(rson(p), mid + 1, r);
//}
//void pushup(int p) {
//	sum(p) = sum(lson(p)) + sum(rson(p));
//}
//void push(int p, int lazy) {
//	lazy(p) += lazy;
//	sum(p) += (r(p) - l(p) + 1) * lazy;
//}
//void pushdown(int p) {
//	if (lazy(p)) {
//		push(lson(p), lazy(p));
//		push(rson(p), lazy(p));
//		lazy(p) = 0;
//	}
//}
//void update(int p, int l, int r, int val) {
//	if (l <= l(p) && r(p) <= r) {
//		push(p, val);
//		return;
//	}
//	pushdown(p);
//	int mid = (l(p) + r(p)) >> 1;
//	if (l <= mid) update(lson(p), l, r, val);
//	if (r > mid) update(rson(p), l, r, val);
//	pushup(p);
//}
//ll query(int p, int l, int r) {
//	if (l <= l(p) && r(p) <= r) {
//		return sum(p);
//	}
//	pushdown(p);
//	ll ans = 0;
//	int mid = (l(p) + r(p)) >> 1;
//	if (l <= mid) ans += query(lson(p), l, r);
//	if (r > mid) ans += query(rson(p), l, r);
//	return ans;
//}
//void ModifyOnTree(int u, int v, int val) {
//	while (top[u] != top[v]) {
//		if (depth[top[u]] < depth[top[v]]) swap(u, v);
//		update(1, dfn[top[u]], dfn[u], val);
//		u = fa[top[u]];
//	}
//	if (depth[u] > depth[v]) swap(u, v);
//	update(1, dfn[u], dfn[v], val);
//}
//ll QueryOnTree(int u, int v) {
//	ll ans = 0;
//	while (top[u] != top[v]) {
//		if (depth[top[u]] < depth[top[v]]) swap(u, v);
//		ans += query(1, dfn[top[u]], dfn[u]);
//		u = fa[top[u]];
//	}
//	if (depth[u] > depth[v]) swap(u, v);
//	ans += query(1, dfn[u], dfn[v]);
//	return ans;
//}
//void init(int n) {
//	cnt = 0; tot = 0;
//	for (int i = 1; i <= n; i++)
//		head[i] = son[i] = val[i] = 0;
//}
//// 上面都是树剖模板 + 初始化
//void solve() {
//	int n=0, m=0;
//	scanf_s("%d%d", &n, &m);
//	init(n);
//	for (int i = 1, u=0, v=0; i < n; i++) {
//		scanf("%d%d", &u, &v);
//		add(u, v); add(v, u);
//	}
//	dfs1(1, 0); dfs2(1, 1);
//	build(1, 1, n);
//	int op, x, w;
//	ll ss = 0, ans = 0, cc = 0;
//	for (int i = 1; i <= m; i++) {
//		scanf_s("%d", &op);
//		if (op == 1) {
//			scanf("%d%d", &x, &w);
//			ss += w - depth[x], cc++;
//			ModifyOnTree(1, x, 2);
//		}
//		else if (op == 2) {
//			scanf_s("%d", &x);
//			ans = ss - cc * depth[x] + QueryOnTree(1, x) + val[x];
//			if (ans > 0) val[x] -= ans;
//		}
//		else {
//			scanf("%d", &x);
//			ans = ss - cc * depth[x] + QueryOnTree(1, x) + val[x];
//			printf("%lld\n", ans);
//		}
//	}
//
//}
////int main() {
////	int t;
////	scanf_s("%d", &t);
////	while (t--) solve();
////	system("pause");
////	return 0;
////}