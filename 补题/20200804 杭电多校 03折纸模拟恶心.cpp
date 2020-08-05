#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<string>
using namespace std;
typedef long long ll;
const int maxn=1e6+50;
const ll mod=1e9+7;

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

int a[200][1050];

void ycl()
{
	a[1][1]=1;
	a[1][2]=2;
	a[1][0]=2;
	for(int i=2;i<=10;i++)
	{
		a[i][0]=(1<<i);
		for(int j=1;j<=a[i-1][0];j++)
		{
			if(j%2)a[i][j]=a[i-1][j]*2-1;
			else a[i][j]=a[i-1][j]*2;
		}
		for(int j=a[i-1][0],k=a[i-1][0]+1;j>=1;j--,k++)
		{
			if(j%2)a[i][k]=a[i-1][j]*2;
			else a[i][k]=a[i-1][j]*2-1;
		}
	}
}

int ans[500][2050];
int b[maxn];
int main()
{
	ycl();
	
	int T=read();
	while(T--)
	{
		int n=read();
		int k=read();
		int r=2*n;
		int c=(1<<k);
		int num=r*c;
		for(int i=1;i<=num;i++)b[i]=read();
		int now=1;
		for(int i=c;i>=1;i--)
		{
			int col=c-a[k][i]+1;
			if(col%2)
			{
				for(int j=r;j>=1;j--)
				{
					ans[j][col]=b[now++];
				}
			}
			else
			{
				for(int j=1;j<=r;j++)
				{
					ans[j][col]=b[now++];
				}
			}
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				printf("%d%c",ans[i][j],i==r&&j==c?'\n':' ');
			}
		}
	}

	return 0;
}
