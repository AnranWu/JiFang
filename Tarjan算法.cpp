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
 
void add(int xx,int y)     //ǰ����
{
    edge[++cnt].next1 = head[xx];
    edge[cnt].c = y;
    head[xx] = cnt;
}
 
void Tarjan(int x)
{
    dfn[x] = low[x] = ++tot;   //����Ҳ��������0����Ϊ0��ʾ��û�п�ʼ���ѣ�Ҫ��1��ʼ
    vis[x] = 1;stact[++index] = x;//ע�������stact�е�0λ����ʲô�����ܴ���ģ���Ϊ����Ҫȥ�ж�ջ��ֱ��ĳһ����ȫ�����������Ҫ�������ĺ�һ��λ�ã����Բ�����0
    for(int i = head[x];i != -1; i = edge[i].next1)//�ҵ�������ȫ����
    {
        int v = edge[i].c;
        if(!dfn[v])     //�����û�����ѹ������
        {
            Tarjan(v);
            low[x] = min(low[x],low[v]);
        }
        else if(vis[v]) //���������Ѿ���ջ���ˣ���ô���ڱ�����������low��Ҫָ�����ĸ��׽ڵ㣬Ҳ����С���Ǹ�
            low[x] = min(low[x],dfn[v]); //�Ƚ�˭��˭�Ķ���
    }
    if(low[x] == dfn[x])   //��ʾ��x֮���ڶ���һ����ͨ�������棬����Ҫȫ�����
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

