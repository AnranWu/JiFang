#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
 
using namespace std;
const int MAXN = 1100;
struct Node
{
    int next1,c;
}edge[MAXN];
int head[MAXN];
int dfn[MAXN],low[MAXN];
int vis[MAXN],stact[MAXN];
int tot,cnt,index;
 
void add(int xx,int y)     //前向星
{
    edge[++cnt].next1 = head[xx];
    edge[cnt].c = y;
    head[xx] = cnt;
}
 
void Tarjan(int x)
{
    dfn[x] = low[x] = ++tot;   //这里也不可以是0，因为0表示还没有开始深搜，要从1开始
    vis[x] = 1;stact[++index] = x;//注意这里的stact中的0位置是什么都不能储存的，因为后面要去判断栈中直到某一个数全部输出，所以要到达他的后一个位置，所以不能是0
    for(int i = head[x];i != -1; i = edge[i].next1)//找到这个点的全部变
    {
        int v = edge[i].c;
        if(!dfn[v])     //如果还没有深搜过这个点
        {
            Tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(vis[v]) //如果这个点已经在栈中了，那么正在遍历的这个点的low就要指向他的父亲节点，也就是小的那个
            low[x] = min(low[x],dfn[v]); //比较谁是谁的儿子
    }
    if(low[x] == dfn[x])   //表示在x之后在都在一个连通分量里面，所以要全部输出
    {
        do{
            printf("%d ",stact[index]);
            vis[stact[index]] = 0;
            index -- ;
        }while(x != stact[index+1]);
        printf("\n");
    }
    return ;
 
}
 
int main()
{
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(stact,0,sizeof(stact));
    tot=0;cnt=0;index=0;
    int n,m;
    scanf("%d%d",&n,&m);
    int xx,y;
    for(int i = 1;i <= m;i ++)
    {
        scanf("%d%d",&xx,&y);
        add(xx,y);
    }
    for(int i = 1; i <= n;i ++)
        if(!dfn[i])
            Tarjan(i);
    return 0;
}

