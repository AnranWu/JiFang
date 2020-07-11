#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<vector>
#include<deque>
#include<stdlib.h>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
#define mem(a,x) memset(a,x,sizeof(a))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const double PI = acos(-1.0);
const ll MAXN = 1e6 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

ll n,p,ans,vis,cnt;
ll a[MAXN],sum[MAXN],c[MAXN],flag[MAXN];
vector<ll>e;

int lowbit(int x)       //求最低位1所代表的数字
{
    return x & -x ;
}

int getsum(int x)       //求1到x的前缀和
{
    int ans=0;
    for(int i=x; i>0; i-=lowbit(i))
        ans+=c[i];
    return ans;
}

void update(int x,int y,int n)//把x处的值更新为y
{
    for(int i=x; i<=n; i+=lowbit(i))
        c[i]+=y;
}


int main()
{
    e.push_back(-inf);//让vector下标从 1 开始记录
	scanf("%lld",&n);
	for(int i = 1;i <= n;i ++)
    {
        scanf("%lld",&a[i]);
        update(i,1,n);
        flag[i] = 1;
    }
	scanf("%lld",&p);
	for(int i = 1;i <= n;i ++)
    {
        a[i] -= p;
        sum[i] = sum[i - 1] + a[i];
        e.push_back(sum[i]);
    }
//    for(int i = 1;i <= n;i ++)printf("%lld ",sum[i]);putchar(10);
    sort(e.begin(),e.end());
    vis = 0;
    int pos = lower_bound(e.begin(),e.end(),0) - e.begin();
    ans += n - pos + 1;
//    printf("ans = %lld\n",ans);
    for(int i = 1;i <= n;i ++)
    {
        vis += a[i];
        pos = lower_bound(e.begin(),e.end(),vis) - e.begin();
        flag[pos] --;
        pos -= flag[pos];
        update(pos,-1,n);
        cnt = getsum(n) - getsum(pos);
//        printf("vis = %lld pos = %d cnt = %lld\n",vis,pos,cnt);
        ans += cnt;
    }
    printf("%lld",ans);
}
/*
9
1 4 5 2 2 1 6 8 2
3
*/

