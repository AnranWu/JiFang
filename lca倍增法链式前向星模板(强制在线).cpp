#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=500005;
int root,n,m,a,b,c;
//保存图结构 
struct node // 链式前向星
{
	int to;
	int next;
}e[2*maxn];
int head[maxn];
int cnt = 1; //对e[]的索引值，初始化为1
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
 
//遍历图，求出各节点的深度，并求出fa数组 
int fa[maxn][20],dep[maxn];
void dfs(int root,int pre)
{
    dep[root]=dep[pre]+1;
    fa[root][0]=pre;
    for(int i=1;(1<<i)<=dep[root];i++)
    	fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].next)
    {
        if(e[i].to!=pre)
        	dfs(e[i].to,root);
    }
}
//查询函数 
int LCA(int a,int b)
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
int main()
{
    cin>>n>>m>>root;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(root,0);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA(a,b));
    }
    return 0;
}

