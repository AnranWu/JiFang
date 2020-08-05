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
ll a[maxn],b[maxn],c[maxn];

struct node
{
	ll l,r,v;
}tree[maxn<<5];

ll rt[maxn],sz;

void build(ll &rt,ll l,ll r)
{
	rt=++sz;
	if(l==r)
	{
		tree[rt].v=0;
		return;
	}
	ll mid=(l+r)>>1;
	build(tree[rt].l,l,mid);
	build(tree[rt].r,mid+1,r);
}

ll update(ll o,ll l,ll r,ll val)
{
	ll oo=++sz;
	tree[oo]=tree[o];
	tree[oo].v++;
	if(l==r)return oo;
	ll mid=(l+r)>>1;
	if(mid>=val)tree[oo].l=update(tree[oo].l,l,mid,val);
	else tree[oo].r=update(tree[oo].r,mid+1,r,val);
	return oo;
}

ll query(ll o,ll l,ll r,ll val)
{
	if(l==r)return l;
	ll mid=(l+r)>>1;
	if(tree[tree[o].l].v>=val)return query(tree[o].l,l,mid,val);
	else return query(tree[o].r,mid+1,r,val-tree[tree[o].l].v);
}

int main()
{
	ll m,n;
	scanf("%lld %lld",&m,&n);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld",&a[i]);
		c[i]=a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	sort(a+1,a+1+m);
	ll q=unique(a+1,a+1+m)-a-1;
	
	build(rt[0],1,q);
	
	for(ll i=1;i<=m;i++)
	{
		ll p=lower_bound(a+1,a+1+q,c[i])-a;
		rt[i]=update(rt[i-1],1,q,p);
	}
	for(ll i=1;i<=n;i++)
	{
		printf("%lld\n",a[query(rt[b[i]],1,q,i)]);
	}
	return 0;
}
