#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

int main()
{
	ll n,ans=0;//ans¼ÇÂ¼n/1+n/2+n/3+...+n/n 
	scanf("%lld",&n);
	for(ll i=1,j;i<=n;i=j+1)
	{
		j=n/(n/i);
		ans+=(j-i+1)*(n/i);
	}
	printf("%lld\n",ans);
}
