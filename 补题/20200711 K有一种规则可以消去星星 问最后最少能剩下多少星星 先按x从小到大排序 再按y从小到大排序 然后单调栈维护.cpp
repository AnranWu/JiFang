#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

struct node
{
	ll x,y;
}a[maxn];

bool cmp(node a,node b)
{
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

ll s[maxn];
ll n;
int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld %lld",&a[i].x,&a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	
	s[0]=0;
	ll top=0;
	
	for(ll i=1;i<=n;i++)
	{
		
		ll tt=a[i].y;
		if(!top)
		{
			s[++top]=tt;
		}
		else
		{
			ll ar=s[top];
			if(tt<ar)s[++top]=tt;
			else
			{
				while(top>0&&s[top]<=tt)
				{
					top--;
				}
				s[++top]=ar;
			}	
		}	
	}
	printf("%lld\n",top);
}


