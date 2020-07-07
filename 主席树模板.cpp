#include<bits/stdc++.h
#define mid (l+r)/2
#define lc o<<1
#define rc o<<1|1
using namespace std;
typedef long long LL;
const int N=100010,LOG=20;
int n,m,q,tot=0;
int a[N],b[N];
int T[N],sum[N*LOG],L[N*LOG],R[N*LOG];
//T数组用于储存根节点.
//sum数组用于储存每一个点被遍历的次数.
//L,R 分别为左儿子和右儿子.
//传统线段树中满足 node*2 即为左儿子,node*2+1 即为右儿子,但主席树中并不满足
//tot 用于记录节点个数和编号.
inline int build(int l, int r)
{
    int rt=++tot;
    if (l<r)
        L[rt]=build(l,mid),
        R[rt]=build(mid+1,r);
    return rt;
}
//我们需要先建立一棵空树.
inline int update(int pre,int l,int r,int x)
{
    int rt=++tot;
    L[rt]=L[pre]; 
    R[rt]=R[pre];
    //先继承上一次插入时的左儿子以及右儿子 
    sum[rt]=sum[pre]+1;
    //因为这里被遍历了一次,所以我们要+1 
    if(l!=r)
    {
        if (x<=mid) L[rt]=update(L[pre],l,mid,x);
        else R[rt]=update(R[pre],mid+1,r,x);
        //如果说需要修改,那么此时上一次的左儿子和右儿子就不适合我们了.
        //所以我们需要将其更改.
    }
    return rt;
}
//每一次依次将排好序的序列加入主席树中.
inline int query(int u, int v, int l, int r, int k)
{
    if (l==r) return l;
    int x=sum[L[v]]-sum[L[u]];
    //查看是往左边走还是往右边走.
    if (x>=k) return query(L[u],L[v],l,mid,k);
    else return query(R[u],R[v],mid+1,r,k-x);
}
//查询时是类似于 Splay 的查询.
int x,y,z; 
int main()
{
    int Test; scanf("%d", &Test);
    while(Test--)
    {
        tot=0;
        memset(T,0,sizeof T); memset(sum,0,sizeof sum);
        memset(L,0,sizeof L); memset(R,0,sizeof R);
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i] = a[i];
        sort(b+1,b+1+n);
        m=unique(b+1,b+1+n)-b-1;
        T[0]=build(1,m);
        for(int i=1;i<=n;i++)
            a[i]=lower_bound(b+1,b+1+m,a[i])-b,
                T[i]=update(T[i-1],1,m,a[i]);
        while (q--)
        {
            scanf("%d%d%d",&x,&y,&z);
            int p=query(T[x-1],T[y],1,m,z);
            printf("%d\n",b[p]);
        }
    }
    return 0;
}
