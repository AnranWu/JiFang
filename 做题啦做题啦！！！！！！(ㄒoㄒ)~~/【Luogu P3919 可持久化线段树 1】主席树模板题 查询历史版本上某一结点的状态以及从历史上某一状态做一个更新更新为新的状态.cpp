#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

struct node
{
	ll l,r,v;
}tree[maxn<<5];

ll rt[maxn],sz=0;
ll a[maxn];
void build(ll &rt,ll l,ll r)
{
	rt=++sz;
	if(l==r)
	{
		tree[rt].v=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(tree[rt].l,l,mid);
	build(tree[rt].r,mid+1,r);
}

ll update(ll o,ll l,ll r,ll pos,ll k)
{
	ll oo=++sz;
	tree[oo]=tree[o];
	if(l==r)
	{
		tree[oo].v=k;
		return oo;
	}
	ll mid=(l+r)>>1;
	if(mid>=pos)tree[oo].l=update(tree[oo].l,l,mid,pos,k);
	else tree[oo].r=update(tree[oo].r,mid+1,r,pos,k);
	return oo;
}

ll query(ll o,ll l,ll r,ll pos)
{
	if(l==r)return tree[o].v;
	ll mid=(l+r)>>1;
	if(mid>=pos)return query(tree[o].l,l,mid,pos);
	else return query(tree[o].r,mid+1,r,pos);
}

int main()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	build(rt[0],1,n);
	for(ll i=1;i<=m;i++)
	{
		ll v,op,pos,k;
		scanf("%lld %lld %lld",&v,&op,&pos);
		if(op==1)
		{
			scanf("%lld",&k);
			rt[i]=update(rt[v],1,n,pos,k);
		}
		else
		{
			rt[i]=rt[v];
			printf("%lld\n",query(rt[v],1,n,pos));
		}
	}
}
