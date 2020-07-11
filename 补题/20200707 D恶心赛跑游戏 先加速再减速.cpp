#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

ll a[maxn];
ll b[maxn];
int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	for(ll i=1;i<=k;i++)
	{
		ll x;
		scanf("%lld",&x);
		if((x*x+x)>=n*2)
		{
			ll ans=ceil((sqrt(8*n+1)-1)/2.0);
			printf("%lld\n",ans);
		}
		else
		{
			ll tt=n+(x*(x-1))/2;
			if(tt*tt<=(x+1)*(x+1))
			{
				ll ff=n-((1+x)*x/2);
				ll ans=x;
				ans+=(ceil((double)ff/(double)x));
				printf("%lld\n",ans);
			}
			else
			{
				ll sudu=ceil(sqrt(n+(x*(x+1))/2.0));
				ll ans=sudu+(sudu-x);
				ll ff=n-((1+sudu)*sudu/2)-((x+sudu-1)*(sudu-1-x+1)/2);
				ans+=(ceil((double)ff/(double)sudu));
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}
