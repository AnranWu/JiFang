/*
多组样例初始化 
void init() {
	ct = 0;
	cnt=0;
	memset(son,0,sizeof(head));
	memset(head,0,sizeof(head));
}
*/ 

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
 
ll n,m,root,mod;

ll cnt=0,top[maxn],siz[maxn],id[maxn],rk[maxn],fa[maxn],dep[maxn],son[maxn];

ll a[maxn];

ll head[maxn],ct=0;

struct node
{
	ll to,nxt;
}e[maxn];

void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

struct nnode
{
	ll l,r,sum,lazy;
}tree[maxn*4];

void dfs1(ll u)
{
	siz[u]=1;dep[u]=dep[fa[u]]+1;
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v!=fa[u])
		{
			fa[v]=u;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
}

void dfs2(ll u,ll tou)
{
	top[u]=tou;
	id[u]=++cnt;
	rk[cnt]=u;
	if(son[u])dfs2(son[u],tou);
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll v=e[i].to;
		if(v!=fa[u]&&v!=son[u])
		{
			dfs2(v,v);
		}
	}
}

ll len(ll rt)
{
	return tree[rt].r-tree[rt].l+1;
}

void pushup(ll rt)
{
	tree[rt].sum=(tree[rt<<1].sum+tree[rt<<1|1].sum)%mod;
}

void pushdown(ll rt)
{
	if(tree[rt].lazy)
	{
		tree[rt<<1].sum=(tree[rt<<1].sum+len(rt<<1)*tree[rt].lazy)%mod;
		tree[rt<<1].lazy+=tree[rt].lazy;
		tree[rt<<1|1].sum=(tree[rt<<1|1].sum+len(rt<<1|1)*tree[rt].lazy)%mod;
		tree[rt<<1|1].lazy+=tree[rt].lazy;
		tree[rt].lazy=0;
	}
}

void build(ll rt,ll l,ll r)
{
	tree[rt].sum=a[rk[l]];
	tree[rt].lazy=0;
	tree[rt].l=l;
	tree[rt].r=r;
	if(l==r)return;
	ll mid=l+r>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}

void update(ll rt,ll l,ll r,ll w)
{
	if(tree[rt].l>=l&&tree[rt].r<=r)
	{
		tree[rt].lazy=(tree[rt].lazy+w)%mod;
		tree[rt].sum=(tree[rt].sum+len(rt)*w)%mod;
		return;
	}
	pushdown(rt);
	ll mid=tree[rt].l+tree[rt].r>>1;
	if(mid>=l)update(rt<<1,l,r,w);
	if(mid<r)update(rt<<1|1,l,r,w);
	pushup(rt);
}

ll query(ll rt,ll l,ll r)
{
	if(tree[rt].l>=l&&tree[rt].r<=r)return tree[rt].sum;
	pushdown(rt);
	ll mid=tree[rt].l+tree[rt].r>>1;
	ll ans=0;
	if(mid>=l)ans+=query(rt<<1,l,r);
	if(mid<r)ans+=query(rt<<1|1,l,r);
	return ans%mod;
}

ll sum(ll x,ll y)
{
	ll ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=(ans+query(1,id[top[x]],id[x]))%mod;
		x=fa[top[x]];
	}
	if(id[x]>id[y])swap(x,y);
	ans=(ans+query(1,id[x],id[y]))%mod;
	return ans;
}

void updates(ll x,ll y,ll z)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],z);
		x=fa[top[x]];
	}
	if(id[x]>id[y])swap(x,y);
	update(1,id[x],id[y],z);
}

int main()
{
	scanf("%lld %lld %lld %lld",&n,&m,&root,&mod);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<n;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(root);
	dfs2(root,root);
	build(1,1,n);
	
	for(ll i=1;i<=m;i++)
	{
		ll op,x,y,z;
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld %lld %lld",&x,&y,&z);
			updates(x,y,z);
		}
		else if(op==2)
		{
			scanf("%lld %lld",&x,&y);
			printf("%lld\n",sum(x,y)%mod);
		}
		else if(op==3)
		{
			scanf("%lld %lld",&x,&z);
			update(1,id[x],id[x]+siz[x]-1,z);
		}
		else
		{
			scanf("%lld",&x);
			printf("%lld\n",query(1,id[x],id[x]+siz[x]-1)%mod);
		}
	}
}
