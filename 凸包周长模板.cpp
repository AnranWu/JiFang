#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define PI 3.1415926535
using namespace std;
struct node
{
    int x,y;
};
node vex[1000];//��������еĵ�
node stackk[1000];//͹�������еĵ�
int xx,yy;
bool cmp1(node a,node b)//�����ҵ�һ����
{
    if(a.y==b.y)
        return a.x<b.x;
    else
        return a.y<b.y;
}
int cross(node a,node b,node c)//������
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(node a,node b)//�������
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y));
}
bool cmp2(node a,node b)//����������һ�ַ������ٶȿ�
{
    if(atan2(a.y-yy,a.x-xx)!=atan2(b.y-yy,b.x-xx))
        return (atan2(a.y-yy,a.x-xx))<(atan2(b.y-yy,b.x-xx));
    return a.x<b.x;
}
bool cmp(node a,node b)//��������
{
    int m=cross(vex[0],a,b);
    if(m>0)
        return 1;
    else if(m==0&&dis(vex[0],a)-dis(vex[0],b)<=0)
        return 1;
    else return 0;
    /*if(m==0)
        return dis(vex[0],a)-dis(vex[0],b)<=0?true:false;
    else
        return m>0?true:false;*/
}
int main()
{
    int t,L;
    while(~scanf("%d",&t),t)
    {
        int i;
        for(i=0; i<t; i++)
        {
            scanf("%d%d",&vex[i].x,&vex[i].y);
        }
        if(t==1)
            printf("%.2f\n",0.00);
        else if(t==2)
            printf("%.2f\n",dis(vex[0],vex[1]));
        else
        {
            memset(stackk,0,sizeof(stackk));
            sort(vex,vex+t,cmp1);
            stackk[0]=vex[0];
            xx=stackk[0].x;
            yy=stackk[0].y;
            sort(vex+1,vex+t,cmp2);//cmp2�Ǹ���ģ�cmp���������
            stackk[1]=vex[1];//��͹���еĵ����������͹���Ľṹ����
            int top=1;//���͹����ӵ�е�ĸ���
            for(i=2; i<t; i++)
            {
                while(i>=1&&cross(stackk[top-1],stackk[top],vex[i])<0)   //��ʹ�ü��������i>=1��ʱ���Բ��ã����������Ǻõ�
                    top--;
                stackk[++top]=vex[i];                                    //����<0��<=0���Կ����ص㣬���ߵģ���������Ŀ������
            }
            double s=0;
            //for(i=1; i<=top; i++)//���͹���ϵĵ�
            //cout<<stackk[i].x<<" "<<stackk[i].y<<endl;
            for(i=1; i<=top; i++)   //����͹�����ܳ�
                s+=dis(stackk[i-1],stackk[i]);
            s+=dis(stackk[top],vex[0]);//���һ����͵�һ����֮��ľ���
            /*s+=2*PI*L;
            int ans=s+0.5;//��������
            printf("%d\n",ans);*/
            printf("%.2lf\n",s);
        }
    }
}
