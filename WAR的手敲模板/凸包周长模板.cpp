#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll top=0,ans[maxn];
struct node
{
	double x,y;
}a[maxn];

bool cmp(node a,node b)
{
	if(a.y==b.y)return a.x<b.x;
	return a.y<b.y;
}
double xx,yy;

bool cmp2(node a,node b)//极角排序另一种方法，速度快
{
    if(atan2(a.y-yy,a.x-xx)!=atan2(b.y-yy,b.x-xx))
        return (atan2(a.y-yy,a.x-xx))<(atan2(b.y-yy,b.x-xx));
    return a.x<b.x;
}

double dis(ll i,ll j)
{
	return sqrt((a[j].x-a[i].x)*(a[j].x-a[i].x)+(a[j].y-a[i].y)*(a[j].y-a[i].y));
}

double cross(ll i,ll j,ll k)
{
	return (a[j].x-a[i].x)*(a[k].y-a[i].y)-(a[j].y-a[i].y)*(a[k].x-a[i].x);
}


int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lf %lf",&a[i].x,&a[i].y);
	}
	if(n==1)printf("0.00\n");
	else if(n==2)printf("%.2lf\n",dis(0,1));
	else
	{
		sort(a+1,a+1+n,cmp);
		xx=a[1].x,yy=a[1].y;
		ans[++top]=1;
		
		sort(a+1,a+1+n,cmp2);
		for(ll i=2;i<=n;i++)
		{
			while(top>1&&cross(ans[top-1],ans[top],i)<0)top--;
			ans[++top]=i;
		}
	}
	double ansnum=0;
	for(ll i=2;i<=top;i++)
	{
		ansnum+=(dis(ans[i-1],ans[i]));
	}
	printf("%.2lf\n",ansnum+dis(ans[top],ans[1]));
}
