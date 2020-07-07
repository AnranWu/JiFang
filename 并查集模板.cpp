#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int parent[1000],n,m,sum;
//parent数组存储的是每个强盗的父亲即boss、sum用来记录犯罪团伙的数量
void Init()
{
    for(int i = 1;i <= n;i++)
        parent[i] = i;
    return;
}

int get_boss(int v)
{
    if(parent[v] == v)
        return v;
    else
    {
        //路径压缩(使搜索祖宗的过程中，路径中搜索的结点的父亲的变为祖宗)
        parent[v] = get_boss(parent[v]);
        return parent[v];
    }
}

void Merge(int v,int u)
{
    int t1 = get_boss(v);
    int t2 = get_boss(u);
    parent[t2] = t1;
    return;
}

int main()
{
    int i,a,b;

    scanf("%d %d",&n,&m);
    //初始化，让每个强盗的父亲都是自己
    Init();
    for(i = 0;i < m;i++)
    {
        scanf("%d %d",&a,&b);
        Merge(a,b);
    }
    //遍历parent数组，如果强盗的父亲还是自己，那么就是一个犯罪团伙
    for(i = 1;i <= n;i++)
    {
        if(parent[i] == i)
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}

