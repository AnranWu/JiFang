//��͹����ʱ�临�Ӷ�nlogn
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

const int MaxN=10010;

int n,tot;//nΪ��ĸ�����totΪ͹��ĸ���
struct point
{
    double x,y;
};
point p[MaxN],CHP[MaxN];//CHPΪ͹����������ɵĵ�

bool cmp(point a,point b)//ˮƽ���򣬰�x�Ӵ�С�ţ����x��ͬ����y�Ӵ�С����
{
    return (a.x<b.x||(a.x==b.x&&a.y<b.y));
}

double xmul(point a,point b,point c)//���
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

void Andrew()
{
    sort(p,p+n,cmp);
    tot=0;

    for(int i=0;i<n;++i)//�����°��͹��
    {
        while(tot>1&&xmul(CHP[tot-2],CHP[tot-1],p[i])<0)
            --tot;
        CHP[tot++]=p[i];
    }

    int k=tot;
    for(int i=n-2;i>=0;--i)//�����ϰ��͹��
    {
        while(tot>k&&xmul(CHP[tot-2],CHP[tot-1],p[i])<0)
            --tot;
        CHP[tot++]=p[i];
    }

    if(n>1)//����ֻ��һ����İ��ٵ����ж�
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
