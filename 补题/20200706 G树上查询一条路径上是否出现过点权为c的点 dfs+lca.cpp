#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

ll n,m;
ll a[maxn];

struct node
{
	ll to,nxt;
}e[maxn];

struct nnode
{
	ll lca,c,id,nxt;
}g[maxn];

ll head[maxn],ct=0,hed[maxn],cnt=0;

void add(ll u,ll v)
{
	e[++ct].to=v;
	e[ct].nxt=head[u];
	head[u]=ct;
}

void ad(ll u,ll lca,ll c,ll id)
{
	g[++cnt].lca=lca;
	g[cnt].c=c;
	g[cnt].id=id;
	g[cnt].nxt=hed[u];
	hed[u]=cnt;
}

//遍历图，求出各节点的深度，并求出fa数组 
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
//查询函数 
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

ll ans[maxn];
ll QAQ[maxn];//QAQ[i]记录点权为i的点在当前结点到根的路径上出现的最深的深度 
void dfs(ll u,ll fa,ll dep)
{
	ll last=QAQ[a[u]];
	QAQ[a[u]]=dep;
	
	for(ll i=hed[u];i;i=g[i].nxt)
	{
		ans[g[i].id]|=(QAQ[g[i].c]>=g[i].lca);
	}
	
	for(ll i=head[u];i;i=e[i].nxt)
	{
		if(e[i].to==fa)continue;
		dfs(e[i].to,u,dep+1);
	}
	QAQ[a[u]]=last;
	
}

int main()
{
	scanf("%lld %lld",&n,&m);
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
	lca_dfs(1,1);
	for(ll i=1;i<=m;i++)
	{
		ll a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		ll lac=lca(a,b);
		ad(a,dep[lac],c,i);
		ad(b,dep[lac],c,i);
	}
	dfs(1,0,1);
	
	for(ll i=1;i<=m;i++)
	{
		printf("%lld",ans[i]);
	}
	printf("\n");
	
}
