#include<bits/stdc++.h>
#define closeSync ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long ll;

int tree[1000050],cnt;

int lowbit(int x)
{
    return x&(-x);
}
void add(int p,int d)
{
    while(p<=cnt)
    {
        tree[p]+=d;
        p+=lowbit(p);
    }
}
int gsum(int p)
{
    int r=0;
    while(p>0)
    {
        r+=tree[p];
        p-=lowbit(p);
    }
    return r;
}

int n;
int a[1000050];
ll sum[1000050];

void solve()
{
    ll p,ans=0,ssum=0;
    rep(i,1,n)
        cin>>a[i];
    cin>>p;
    
    sum[1]=0;
    rep(i,1,n)
    {
        a[i]-=p;
        sum[i+1]=sum[i]+a[i];
    }
    
    sort(sum+1,sum+2+n);
    int len=unique(sum+1,sum+2+n)-sum-1;
    
    map<ll,int> mp;
    rep(i,1,len)
    {
        mp[sum[i]]=i;
        tree[i]=0;
    }
    cnt=len;
    
    add(mp[0],1);
    rep(i,1,n)
    {
        ssum+=a[i];
        int pos=mp[ssum];
        ans+=gsum(pos);
        add(pos,1);
    }
    cout<<ans<<'\n';
}
int main()
{
    closeSync;
    while(cin>>n)
    {
        solve();
    }
    return 0;
}

