#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll a[5][maxn];
ll sum[5][maxn];
ll dp[5][maxn];
ll minv[5][maxn];
ll n;
ll work()
{
	dp[0][0]=0;
	minv[1][0]=4e18;
	minv[2][0]=4e18;
	minv[3][0]=4e18;
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			dp[i][j]=minv[i-1][j-1]+sum[i][j];
			minv[i][j]=min(minv[i][j-1],dp[i][j]-sum[i+1][j]);
		}
	}
	return dp[3][n];
}


int main()
{
	
	scanf("%lld",&n);
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	ll ans=work();
	swap(a[2],a[3]);swap(sum[2],sum[3]);
	ans=min(ans,work());
	swap(a[1],a[2]);swap(sum[1],sum[2]);
	ans=min(ans,work());
	swap(a[2],a[3]);swap(sum[2],sum[3]);
	ans=min(ans,work());
	swap(a[1],a[2]);swap(sum[1],sum[2]);
	ans=min(ans,work());
	swap(a[2],a[3]);swap(sum[2],sum[3]);
	ans=min(ans,work());
	printf("%lld\n",ans);
}
