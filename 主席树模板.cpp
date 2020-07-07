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
//T�������ڴ�����ڵ�.
//sum�������ڴ���ÿһ���㱻�����Ĵ���.
//L,R �ֱ�Ϊ����Ӻ��Ҷ���.
//��ͳ�߶��������� node*2 ��Ϊ�����,node*2+1 ��Ϊ�Ҷ���,����ϯ���в�������
//tot ���ڼ�¼�ڵ�����ͱ��.
inline int build(int l, int r)
{
    int rt=++tot;
    if (l<r)
        L[rt]=build(l,mid),
        R[rt]=build(mid+1,r);
    return rt;
}
//������Ҫ�Ƚ���һ�ÿ���.
inline int update(int pre,int l,int r,int x)
{
    int rt=++tot;
    L[rt]=L[pre]; 
    R[rt]=R[pre];
    //�ȼ̳���һ�β���ʱ��������Լ��Ҷ��� 
    sum[rt]=sum[pre]+1;
    //��Ϊ���ﱻ������һ��,��������Ҫ+1 
    if(l!=r)
    {
        if (x<=mid) L[rt]=update(L[pre],l,mid,x);
        else R[rt]=update(R[pre],mid+1,r,x);
        //���˵��Ҫ�޸�,��ô��ʱ��һ�ε�����Ӻ��Ҷ��ӾͲ��ʺ�������.
        //����������Ҫ�������.
    }
    return rt;
}
//ÿһ�����ν��ź�������м�����ϯ����.
inline int query(int u, int v, int l, int r, int k)
{
    if (l==r) return l;
    int x=sum[L[v]]-sum[L[u]];
    //�鿴��������߻������ұ���.
    if (x>=k) return query(L[u],L[v],l,mid,k);
    else return query(R[u],R[v],mid+1,r,k-x);
}
//��ѯʱ�������� Splay �Ĳ�ѯ.
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
