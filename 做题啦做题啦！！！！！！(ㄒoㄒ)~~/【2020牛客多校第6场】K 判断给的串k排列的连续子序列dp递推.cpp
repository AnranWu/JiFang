#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
const ll maxn=1e6+50;
unordered_map<int,int>sum;
int dp[maxn];
int a[maxn];

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

int main()
{
	int T;
	T=read();
	while(T--)
	{
		int n,k;
		n=read();
		k=read();
		int tot=0;
		sum.clear();
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		bool flag=0;
		for(ll i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]>k)flag=1;
		}
		if(flag){printf("NO\n");continue;}
		for(int i=1;i<=n;i++)
		{
			if(i>k)if(!--sum[a[i-k]])tot--;
			if(!sum[a[i]])tot++;
			sum[a[i]]++;
			if(tot==k||tot==i)dp[i]=i-k>=0?dp[i-k]:1;
		}
		tot=0;
		sum.clear();
		bool ans=0;
		for(int i=n;i>=max(n-k,0);i--)
		{
			if(dp[i]&&tot==n-i){ans=1;break;}
			if(!sum[a[i]])tot++;
			sum[a[i]]++;
		}
		printf("%s\n",ans?"YES":"NO");
	}
}
