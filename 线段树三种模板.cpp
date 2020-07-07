#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int N = 1e5 + 10;
 
#define lson rt << 1	  // == rt * 2	 �����
#define rson rt << 1 | 1  // == rt * 2 + 1 �Ҷ���
#define int_mid int mid = tree[rt].l + tree[rt].r >> 1
 
int a[N]; // ��ʼֵ
 
struct node {
	int l, r;
	ll val, lazy;
} tree[N * 4];
 
void push_up(int rt) {
	//tree[rt].val = min(tree[lson].val, tree[rson].val);
	//tree[rt].val = max(tree[lson].val, tree[rson].val);
	tree[rt].val = tree[lson].val + tree[rson].val;
}
 
void push_down(int rt) {
	if (tree[rt].lazy) {
		tree[lson].lazy += tree[rt].lazy;
		tree[rson].lazy += tree[rt].lazy;
		//{ // ά�������Сֵ
		//	tree[lson].val += tree[rt].lazy;
		//	tree[rson].val += tree[rt].lazy;
		//}
		{ // ά����
			int l = tree[rt].l, r = tree[rt].r;
			int mid = l + r >> 1;
			tree[lson].val += 1ll * (mid - l + 1) * tree[rt].lazy;
			tree[rson].val += 1ll * (r - mid) * tree[rt].lazy;
		}
		tree[rt].lazy = 0;
	}
}
 
void build(int rt, int l, int r) { // ����
	tree[rt].l = l, tree[rt].r = r;
	tree[rt].lazy = 0;
	if (l == r) {
		tree[rt].val = a[l]; // ����һ����ʼֵ
		return;
	} else {
		int mid = l + r >> 1; // (l + r) / 2
		build(lson, l, mid);
		build(rson, mid + 1, r);
		push_up(rt);
	}
}
 
void update_point(int rt, int pos, ll val) { // �������
	if (tree[rt].l == tree[rt].r && pos == tree[rt].l) {
		tree[rt].val += val;
		return;
	}
	int_mid;
	if (pos <= mid) update_point(lson, pos, val);
	else update_point(rson, pos, val);
	push_up(rt);
}
 
void update_interval(int rt, int l, int r, ll val) { // �������
	if (l <= tree[rt].l && r >= tree[rt].r) {
		tree[rt].lazy += val;
		//tree[rt].val += val; // ά�������Сֵ
		tree[rt].val += 1ll * (tree[rt].r - tree[rt].l + 1) * val; // ά���� 
		return;
	}
	push_down(rt);
	int_mid;
	if (l <= mid) update_interval(lson, l, r, val);
	if (r > mid) update_interval(rson, l, r, val);
	push_up(rt);
}
 
ll query_point(int rt, int pos) { // �����ѯ
	if (tree[rt].l == tree[rt].r && tree[rt].l == pos)
		return tree[rt].val;
	push_down(rt);
	int_mid;
	if (pos <= mid) query_point(lson, pos);
	else query_point(rson, pos);
}
 
ll query_interval(int rt, int l, int r) { // �����ѯ
	if (l <= tree[rt].l && r >= tree[rt].r)
		return tree[rt].val;
	push_down(rt);
	int_mid;
	if (r <= mid) return query_interval(lson, l, r);
	else if (l > mid) return query_interval(rson, l, r);
	else {
		//return min(query_interval(lson, l, mid), query_interval(rson, mid + 1, r));
		//return max(query_interval(lson, l, mid), query_interval(rson, mid + 1, r));
		return query_interval(lson, l, mid) + query_interval(rson, mid + 1, r);
	}
}

