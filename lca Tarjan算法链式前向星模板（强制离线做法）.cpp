#include<bits/stdc++.h>
#define ll int
#define endl '\n'
#define IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int maxn=5e5+5;
bool vis[maxn];int head[maxn],hea[maxn];int fa[maxn];
int n,m,s;
int tot,cnt;
struct E{
	int to,next;
}edge[maxn<<1];

struct E2{
	int to,next,lca;
}edge2[maxn<<1];

inline void add(int u,int v){
	edge[tot].to=v;
	edge[tot].next=head[u];
	head[u]=tot++;
}

inline void add2(int u,int v){
	edge2[cnt].to=v;
	edge2[cnt].next=hea[u];
	hea[u]=cnt++;
}

int find(int x){
	while(fa[x]!=x) x=fa[x]=fa[fa[x]];
	return x;
}
void tarjan(int x){
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next){
		int v=edge[i].to;
		if(vis[v]) continue;
		tarjan(v);
		fa[find(v)]=find(x);
	}
	for(int i=hea[x];i;i=edge2[i].next){
		int v=edge2[i].to;
		if(vis[v]) edge2[i].lca=find(v);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	tot=1,cnt=1;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		add2(x,y);add2(y,x);
	}	
	tarjan(s);
    for(int i=1;i<cnt;i+=2)
        printf("%d\n",edge2[i].lca==0?edge2[i+1].lca:edge2[i].lca);	
}

