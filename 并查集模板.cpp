#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int parent[1000],n,m,sum;
//parent����洢����ÿ��ǿ���ĸ��׼�boss��sum������¼�����Ż������
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
        //·��ѹ��(ʹ�������ڵĹ����У�·���������Ľ��ĸ��׵ı�Ϊ����)
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
    //��ʼ������ÿ��ǿ���ĸ��׶����Լ�
    Init();
    for(i = 0;i < m;i++)
    {
        scanf("%d %d",&a,&b);
        Merge(a,b);
    }
    //����parent���飬���ǿ���ĸ��׻����Լ�����ô����һ�������Ż�
    for(i = 1;i <= n;i++)
    {
        if(parent[i] == i)
            sum++;
    }
    printf("%d\n",sum);
    return 0;
}

