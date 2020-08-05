#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll a[5][maxn];
ll s1[5][maxn];
ll s2[5][maxn];
ll f[5][5][maxn];
int main()
{
	ll n;
	scanf("%lld",&n);
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			s1[i][j]=s1[i][j-1]+a[i][j];
		}
	}
	for(ll i=1;i<=3;i++)
	{
		for(ll j=n;j>=1;j--)
		{
			s2[i][j]=s2[i][j+1]+a[i][j];
		}
	}
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=3;j++)
		{
			f[i][j][n+1]=4e18;
		}
	}
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=3;j++)
		{
			if(i==j)continue;
			for(ll k=n;k>2;k--)
			{
				f[i][j][k]=min(f[i][j][k+1],s2[j][k]-s2[i][k]);
			}
		}
	}
	ll ans=4e18;
	for(ll i=1;i<=3;i++)
	{
		for(ll j=1;j<=3;j++)
		{
			if(i==j)continue;
			for(ll k=1;k<=n-2;k++)
			{
				ans=min(ans,s1[6-i-j][k]+s2[i][k+1]+f[i][j][k+2]);
			}
		}
	}
	printf("%lld\n",ans);
}
