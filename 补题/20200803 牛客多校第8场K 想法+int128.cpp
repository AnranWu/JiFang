#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const ll maxn=1e6+50;

inline lll read()
{
    lll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
inline void write(lll x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);putchar(x%10+'0');
}

ll n;
lll ans=0;
ll a[maxn],b[maxn],mi[maxn];
lll sum[maxn];
  
void init()
{
    ans=0;
    mi[0]=4e18;
    sum[0]=0;
}
  
struct node
{
    lll x;
    ll id;
}ss[maxn];
  
bool cmp(node a,node b)
{
    if(a.x==b.x)return a.id>b.id;
    return a.x>b.x;
}
  
int main()
{
    ll T,Case=1;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        init();
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);//利润
            sum[i]=sum[i-1]+a[i];//前缀和
            ss[i].id=i;
            ss[i].x=sum[i];
        }
        sort(ss+1,ss+1+n,cmp);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&b[i]);//份数
            mi[i]=min(mi[i-1],b[i]);
        }
        ll now = 0,nowi = n + 1;
        //for(int i=1;i<=n;i++)printf("%lld %lld\n",ss[i].id,ss[i].x);
        for(int i=1;i<=n;i++)
        {
            if(ss[i].id>nowi)continue;
            mi[ss[i].id]-=now;
            if(mi[ss[i].id]>=0)
            {
                ans+=(ss[i].x*mi[ss[i].id]);
                now+=mi[ss[i].id];
                nowi=ss[i].id;
            }
        }
        printf("Case #%lld: %lld ",Case++,b[1]);
        write(ans);
        putchar(10);
    }
  
}
