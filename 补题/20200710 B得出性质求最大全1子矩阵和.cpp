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
const ll maxn=1e3+50;

ll b[1050][1050];
ll ss[1050][1050];
ll ans;

ll s[maxn],r[maxn],l[maxn];
int f[1050][1050];
ll n,m;

void g(int x)
{
	s[0]=0;
	ll top=0;
	f[x][m+1]=0;
	for(ll i=1;i<=m+1;i++)
	{
		ll ar=s[top];
		while(f[x][i]<f[x][ar])
		{
			r[ar]=i;
			top--;
			ar=s[top];
		}
		l[i]=ar;
		s[++top]=i;
	}
	for(ll i=1;i<=m;i++)
	{
		if(f[x][i])
		{
			ll kuan=(r[i]-l[i]-1);
			ll ga=f[x][i];
			if(ans<(ga+1)*(kuan+1))
			{
				ans=(ga+1)*(kuan+1);
			}
		}
			
	}
}

int main()
{
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			scanf("%lld",&b[i][j]);
		}
	}
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<m;j++)
		{
			if(b[i][j]+b[i+1][j+1]<=b[i+1][j]+b[i][j+1])ss[i][j]=1;
			else ss[i][j]=0;
		}
	}
	n--,m--;
	for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)if(ss[i][j]==1)f[i][j]=f[i-1][j]+1;
	
	for(ll i=1;i<=n;i++)g(i);
	printf("%lld\n",ans);
}
