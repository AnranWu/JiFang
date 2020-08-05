#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

int main()
{
	ll n,k;
	scanf("%lld %lld",&k,&n);
	ll ans=n*k;
	ll mi=min(k,n);
	for(ll i=1,j;i<=mi;i=j+1)
	{
		j=n/(n/i);
		j=min(j,mi);
		ans-=((j-i+1)*(n/i)*(i+j)/2);
	}
	printf("%lld\n",ans);
}
/*
luogu P2261 整除分块模板题 
*/

