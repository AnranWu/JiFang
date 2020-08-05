#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;

struct node
{
	int num,x;
}a[maxn];
int ct=0,sum=0;

void dfs(int n,int m)
{
	if(n==m)
	{
		a[ct].num+=n;
		sum+=n;
		return;
	}
	if(n<m)swap(n,m);
	a[++ct].num=m;
	sum+=m;
	a[ct].x=m;
	dfs(n-m,m);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		ct=0;
		sum=0;
		dfs(n,m);
		if(n==m)
		{
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("%d%c",n,i==n?'\n':' ');
			continue;
		}
		printf("%d\n",sum);
		for(int i=1;i<=ct;i++)
		{
			for(int j=1;j<=a[i].num;j++)
			{
				printf("%d ",a[i].x);
			}
		}
		putchar(10);
	}
	return 0;
}
