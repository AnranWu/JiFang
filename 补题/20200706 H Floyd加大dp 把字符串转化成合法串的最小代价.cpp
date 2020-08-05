#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn=1e5+50;
const ll mod=1e9+7;

char s[maxn];
ll dis[100][100];
ll sum[maxn][50];
ll dp[maxn][50];
ll mi[maxn];

int main()
{
	ll n,m,k;
	scanf("%lld %lld %lld",&n,&m,&k);
	scanf("%s",s+1);
	memset(dp,0x3f,sizeof(dp));
	memset(dis,0x3f,sizeof(dis));
	for(ll i=0;i<m;i++)for(ll j=0;j<m;j++)scanf("%lld",&dis[i][j]);
	for(ll k=0;k<m;k++)for(ll i=0;i<m;i++)for(ll j=0;j<m;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(ll i=1;i<=n;i++)for(ll j=0;j<m;j++)sum[i][j]=sum[i-1][j]+dis[s[i]-'a'][j];
	memset(mi,0x3f,sizeof(mi));
	for(ll i=0;i<m;i++)
	{
		dp[k][i]=0;
		for(ll j=1;j<=k;j++)
		{
			dp[k][i]+=dis[s[j]-'a'][i];
		}
		mi[k]=min(mi[k],dp[k][i]);
	}
	
	for(ll i=k+1;i<=n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i-1][j]+dis[s[i]-'a'][j]);
			mi[i]=min(mi[i],dp[i][j]);
			if(i+k-1>n)continue;
			ll nd=sum[i+k-1][j]-sum[i-1][j];
			dp[i+k-1][j]=min(dp[i+k-1][j],mi[i-1]+nd);
		}
	}
	
	printf("%lld\n",mi[n]);
	
}
 
