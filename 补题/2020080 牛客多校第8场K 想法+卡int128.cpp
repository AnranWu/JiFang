#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
typedef __int128 ll;
const ll maxn=1e5+50;
  
int n;
ll ans=0;
ll a[maxn],b[maxn];
ll sum[maxn],tmp[maxn],mx[maxn],mi[maxn];
  
inline __int128 read()
{
    __int128 x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9' )
    {
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
  
inline void write(__int128 x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
  
void init()
{
    ans=0;
    mi[0]=2e9;
}
  
struct node
{
    ll id,x;
}ss[maxn];
  
bool cmp(node a,node b)
{
    if(a.x==b.x)return a.id>b.id;
    return a.x>b.x;
}
  
int main()
{
    int T,Case=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)
        {
            a[i] = read();
            sum[i]=sum[i-1]+a[i];//Ç°×ººÍ
            ss[i].id=i;
            ss[i].x=sum[i];
        }
        sort(ss+1,ss+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            b[i] = read();
            mi[i]=min(mi[i-1],b[i]);
        }
        ll now = 0,nowi = n + 1;
        for(int i=1;i<=n;i++)
        {
            if(ss[i].id>nowi)continue;
            mi[ss[i].id]-=now;
            if(mi[ss[i].id]>=0)
            {
                ans += (ss[i].x*mi[ss[i].id]);
                now += mi[ss[i].id];
                nowi=ss[i].id;
            }
        }
        printf("Case #%d:",Case ++);
        printf(" ");
        write(b[1]);
        printf(" ");
        write(ans);
        putchar(10);
    }
  
}
