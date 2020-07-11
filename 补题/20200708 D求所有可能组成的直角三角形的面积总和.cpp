#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
const ll maxn=2e6+50;
const ll mod=1e9+7;

struct node
{
	ll x,y;
}a[maxn];

ll nx[maxn],ny[maxn],sx[maxn],sy[maxn],ans=0,n;

bool cmp1(node a,node b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

bool cmp2(node a,node b)
{
	if(a.x==b.x)return a.y>b.y;
	return a.x<b.x;
}

bool cmp3(node a,node b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x>b.x;
}

bool cmp4(node a,node b)
{
	if(a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}

void init()
{
	memset(nx,0,sizeof(nx));
	memset(ny,0,sizeof(ny));
	memset(sx,0,sizeof(sx));
	memset(sy,0,sizeof(sy));
}

void deal()
{
	for(ll i=1;i<=n;i++)
	{
		ll x=a[i].x+10000;
		ll y=a[i].y+10000;
		if(nx[x]&&ny[y])
		{
			ans=(ans+abs((x*ny[y]-sy[y])*(y*nx[x]-sx[x]))%mod)%mod;
		}
		nx[x]++;ny[y]++;
		sx[x]+=y;sy[y]+=x;
	}
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a[i].x,&a[i].y);
	}
	
	sort(a+1,a+1+n,cmp1);
	deal();
	
	sort(a+1,a+1+n,cmp2);
	init();
	deal();
	
	sort(a+1,a+1+n,cmp3);
	init();
	deal();
	
	sort(a+1,a+1+n,cmp4);
	init();
	deal();
	printf("%lld\n",ans);
}

