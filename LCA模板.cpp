#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<fstream>
using namespace std;
#define maxn 501000
int n,m,s;
int dep[maxn<<1];
int f[maxn<<1][21];
int head[maxn<<1],cnt=0;
struct hh
{
    int nex,to;
}t[maxn<<1];
inline void add(int nex,int to)
{
    t[++cnt].nex=head[nex];
    t[cnt].to=to;
    head[nex]=cnt;
}
inline void Deal_first(int u,int fa)
{
    dep[u]=dep[fa]+1;
    for(int i=0;i<20;i++)
        f[u][i+1]=f[f[u][i]][i];
    for(int i=head[u];i;i=t[i].nex)
    {
        int v=t[i].to;
        if(v==fa) continue;
        f[v][0]=u;
        Deal_first(v,u);
    }
return;
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--)
    {
        if(dep[f[x][i]]>=dep[y]) x=f[x][i];
        if(x==y) return x;
    }
    for(int i=20;i>=0;i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
inline int read()
{
    int kr=1,xs=0;
    char ls;
    ls=getchar();
    while(!isdigit(ls))
    {
        if(!(ls^45))
            kr=-1;
        ls=getchar();
    }
    while(isdigit(ls))
    {
        xs=(xs<<1)+(xs<<3)+(ls^48);
        ls=getchar();
    }
    return xs*kr;
}
int main()
{
    int x,y;
    n=read();m=read();s=read();//n个节点，m个询问，以s为根节点 
    for(int i=1;i<n;i++)
    {
        x=read();y=read();
        add(x,y);
        add(y,x);//添加无向边 
    }
    Deal_first(s,0);//以点s为根节点预处理 f 数组 
    for(int i=1;i<=m;i++)
    {
        x=read();y=read();
        printf("%d\n",LCA(x,y));
    }
return 0;
}
