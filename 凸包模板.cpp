//求凸包，时间复杂度nlogn
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int MaxN=10010;

int n,tot;//n为点的个数，tot为凸点的个数
struct point
{
    double x,y;
};
point p[MaxN],CHP[MaxN];//CHP为凸包最后所构成的点

bool cmp(point a,point b)//水平排序，按x从大到小排，如果x相同，按y从大到小排序
{
    return (a.x<b.x||(a.x==b.x&&a.y<b.y));
}

double xmul(point a,point b,point c)//叉积
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

void Andrew()
{
    sort(p,p+n,cmp);
    tot=0;

    for(int i=0;i<n;++i)//计算下半个凸包
    {
        while(tot>1&&xmul(CHP[tot-2],CHP[tot-1],p[i])<0)
            --tot;
        CHP[tot++]=p[i];
    }

    int k=tot;
    for(int i=n-2;i>=0;--i)//计算上半个凸包
    {
        while(tot>k&&xmul(CHP[tot-2],CHP[tot-1],p[i])<0)
            --tot;
        CHP[tot++]=p[i];
    }

    if(n>1)//对于只有一个点的包再单独判断
        --tot;
}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    Andrew();
    printf("tot=%d\n",tot);
    for(int i=0;i<tot;++i)
    {
        printf("%d: %.2lf , %.2lf\n",i+1,CHP[i].x,CHP[i].y);
    }
    return 0;
}
