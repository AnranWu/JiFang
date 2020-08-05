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
const ll M=1e6;
ll a[maxn],t[maxn*2];
ll sum[5050][5050];
int main()
{
	ll n,q;
	scanf("%lld %lld",&n,&q);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			ll tt=-a[i]-a[j];
			if(j>=i+2&&tt+M>=0&&tt+M<=2000000)
			{
				sum[i][j]=t[tt+M];//sum[i][j]表示的是左端点为i右端点为j时答案为多少 
			}
			t[a[j]+M]++;
		}
		for(ll j=i+1;j<=n;j++)t[a[j]+M]--;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];//做二维前缀和是为了维护这个区间内所有的答案而不是只要以ij为左右端点的答案 
		}
	}
	
	for(ll i=1;i<=q;i++)
	{
		ll l,r;
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",sum[r][r]-sum[l-1][r]-sum[r][l-1]+sum[l-1][l-1]);//二维差分得出答案 
	}
}
