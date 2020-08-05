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

struct nnode
{
	ll nxt,to;
}e[maxn];
ll head[maxn],ct,ans[maxn];
void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

struct node
{
	ll l,r,v;
}tree[maxn<<5];

ll rt[maxn],sz;
ll n,m;
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

ll query(ll x,ll y,ll a,ll b,ll l,ll r,ll val)
{
	if(l==r)return tree[x].v+tree[y].v-tree[a].v-tree[b].v;
	ll mid=(l+r)>>1;
	if(mid>=val)return query(tree[x].l,tree[y].l,tree[a].l,tree[b].l,l,mid,val);
	else return query(tree[x].r,tree[y].r,tree[a].r,tree[b].r,mid+1,r,val);
}

int fa[maxn][20],dep[maxn];
void lca_dfs(int root,int pre)
{
    dep[root]=dep[pre]+1;
    fa[root][0]=pre;
    for(int i=1;(1<<i)<=dep[root];i++)
    	fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].nxt)
    {
        if(e[i].to!=pre)
        	lca_dfs(e[i].to,root);
    }
}

int lca(int a,int b)
{
    if(dep[a]<dep[b]) // 确定a的深度大于等于b的深度
        swap(a,b);
    for(int i=19;i>=0;i--) //2^19 = 524,288>maxn 真实这里的19要根据最深的深度自适应
    {
        if(dep[a]-(1<<i)>=dep[b]) // 倍增的方式跳到与b同一深度
            a=fa[a][i]; // 或者当前深度的a的祖先
    }
    if(a==b) // 到一起了，b是a的祖先
        return a;
    for(int i=19;i>=0;i--)// 同时向上
    {
        if(fa[a][i]!=fa[b][i])// 共同祖先是不会回溯的，得是共同祖先再深一层（分叉）
        {
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}

void dfs(ll u,ll fa)
{
	rt[u]=update(rt[fa],1,n,a[u]);
	for(ll i=head[u];i;i=e[i].nxt)
	{
		ll to=e[i].to;
		if(to!=fa)dfs(to,u);
	}
}

int main()
{
	
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		c[i]=a[i];
	}
	for(ll i=1;i<n;i++)
	{
		ll u,v;
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	build(rt[0],1,n);
	lca_dfs(1,0);
	dfs(1,0);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		scanf("%lld %lld %lld",&x,&y,&z);
		ll lac=lca(x,y);
		ans[i]=(query(rt[x],rt[y],rt[lac],rt[fa[lac][0]],1,n,z)?1:0);
	}
	for(ll i=1;i<=m;i++)printf("%lld",ans[i]);
	putchar(10);
	return 0;
}
