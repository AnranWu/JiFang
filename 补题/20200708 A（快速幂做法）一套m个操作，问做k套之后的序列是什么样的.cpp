#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll tmp[maxn],n,m,k,anow[maxn],a[maxn],b[maxn],t[maxn];
void change(ll flag)
{
	if(flag)
	{
		for(ll i=1;i<=n;i++)
		{
			tmp[i]=anow[t[i]];
		}
		for(ll i=1;i<=n;i++)
		{
			anow[i]=tmp[i];
		}
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			tmp[i]=t[t[i]];
		}
		for(ll i=1;i<=n;i++)
		{
			t[i]=tmp[i];
		}
	}
}

int main()
{
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
	{
		scanf("%lld %lld",&a[i],&b[i]);
	}
	for(ll i=1;i<=n;i++)
	{
		t[i]=i;
		anow[i]=i;
	}
	for(ll i=1;i<=m;i++)
	{
		for(ll j=a[i],k=b[i];j<k;j++,k--)
		{
			swap(t[j],t[k]);
		}
	}

	while(k)
	{
		if(k&1)change(1);
		change(0);
		k>>=1;
	}
	for(ll i=1;i<=n;i++)
	{
		printf("%lld\n",anow[i]);
	}
	
}
