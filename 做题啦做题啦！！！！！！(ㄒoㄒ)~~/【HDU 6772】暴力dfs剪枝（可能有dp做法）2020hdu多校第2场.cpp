#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
ll hou[maxn];
namespace Fast_IO
{ //orz laofu
    const int MAXL((1 << 18) + 1);int iof, iotp;
    char ioif[MAXL], *ioiS, *ioiT, ioof[MAXL],*iooS=ioof,*iooT=ioof+MAXL-1,ioc,iost[55];
    char Getchar(){
        if (ioiS == ioiT){
            ioiS=ioif;ioiT=ioiS+fread(ioif,1,MAXL,stdin);return (ioiS == ioiT ? EOF : *ioiS++);
        }else return (*ioiS++);
    }
    void Write(){fwrite(ioof,1,iooS-ioof,stdout);iooS=ioof;}
    void Putchar(char x){*iooS++ = x;if (iooS == iooT)Write();}
    inline int read(){
        int x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
		if(ioc==EOF)exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    inline long long read_ll(){
        long long x=0;for(iof=1,ioc=Getchar();(ioc<'0'||ioc>'9')&&ioc!=EOF;)iof=ioc=='-'?-1:1,ioc=Getchar();
		if(ioc==EOF)exit(0);
        for(x=0;ioc<='9'&&ioc>='0';ioc=Getchar())x=(x<<3)+(x<<1)+(ioc^48);return x*iof;
    }
    template <class Int>void Print(Int x, char ch = '\0'){
        if(!x)Putchar('0');if(x<0)Putchar('-'),x=-x;while(x)iost[++iotp]=x%10+'0',x/=10;
        while(iotp)Putchar(iost[iotp--]);if (ch)Putchar(ch);
    }
    void Getstr(char *s, int &l){
        for(ioc=Getchar();ioc==' '||ioc=='\n'||ioc=='\t';)ioc=Getchar();
		if(ioc==EOF)exit(0);
        for(l=0;!(ioc==' '||ioc=='\n'||ioc=='\t'||ioc==EOF);ioc=Getchar())s[l++]=ioc;s[l] = 0;
    }
    void Putstr(const char *s){for(int i=0,n=strlen(s);i<n;++i)Putchar(s[i]);}
} // namespace Fast_IO
using namespace Fast_IO;

struct node
{
	int a,b,c,d;
}a[55][55];
int ct[55];ll n,k;
ll ans=0;

void dfs(ll x,ll sa,ll sb,ll sc,ll sd)
{
	if(x>k)
	{
		ans=max(ans,1ll*(100+sa)*(100+sb)*(100+sc)*(100+sd));
		
		return;
	}
	if(1ll*(100+sa+hou[x]*101)*(100+sb+hou[x]*101)*(100+sc+hou[x]*101)*(100+sd+hou[x]*101)<=ans)return;
	for(ll i=1;i<=ct[x];i++)
	{
		dfs(x+1,sa+a[x][i].a,sb+a[x][i].b,sc+a[x][i].c,sd+a[x][i].d);
	}
	if(ct[x]==0)dfs(x+1,sa,sb,sc,sd);
}

int main()
{
	int t;
	t=read();
	while(t--)
	{
		ans=0;
		n=read();
		k=read();
		memset(ct,0,sizeof(ct));
		memset(hou,0,sizeof(hou));
		for(ll i=1;i<=n;i++)
		{
			int type,aa,bb,cc,dd;
			type=read();
			aa=read();
			bb=read();
			cc=read();
			dd=read();
			a[type][++ct[type]].a=aa;
			a[type][ct[type]].b=bb;
			a[type][ct[type]].c=cc;
			a[type][ct[type]].d=dd;
		}
		for(ll i=k;i>=1;i--)
		{
			hou[i]=hou[i+1]+(ct[i]!=0);
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
}
