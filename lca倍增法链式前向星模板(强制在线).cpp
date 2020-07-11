#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn=500005;
int root,n,m,a,b,c;
//����ͼ�ṹ 
struct node // ��ʽǰ����
{
	int to;
	int next;
}e[2*maxn];
int head[maxn];
int cnt = 1; //��e[]������ֵ����ʼ��Ϊ1
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].next=head[a];
	head[a]=cnt;
}
 
//����ͼ��������ڵ����ȣ������fa���� 
int fa[maxn][20],dep[maxn];
void dfs(int root,int pre)
{
    dep[root]=dep[pre]+1;
    fa[root][0]=pre;
    for(int i=1;(1<<i)<=dep[root];i++)
    	fa[root][i]=fa[fa[root][i-1]][i-1];
    for(int i=head[root];i;i=e[i].next)
    {
        if(e[i].to!=pre)
        	dfs(e[i].to,root);
    }
}
//��ѯ���� 
int LCA(int a,int b)
{
    if(dep[a]<dep[b]) // ȷ��a����ȴ��ڵ���b�����
        swap(a,b);
    for(int i=19;i>=0;i--) //2^19 = 524,288>maxn ��ʵ�����19Ҫ����������������Ӧ
    {
        if(dep[a]-(1<<i)>=dep[b]) // �����ķ�ʽ������bͬһ���
            a=fa[a][i]; // ���ߵ�ǰ��ȵ�a������
    }
    if(a==b) // ��һ���ˣ�b��a������
        return a;
    for(int i=19;i>=0;i--)// ͬʱ����
    {
        if(fa[a][i]!=fa[b][i])// ��ͬ�����ǲ�����ݵģ����ǹ�ͬ��������һ�㣨�ֲ棩
        {
            a=fa[a][i];
            b=fa[b][i];
        }
    }
    return fa[a][0];
}
int main()
{
    cin>>n>>m>>root;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    dfs(root,0);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA(a,b));
    }
    return 0;
}

