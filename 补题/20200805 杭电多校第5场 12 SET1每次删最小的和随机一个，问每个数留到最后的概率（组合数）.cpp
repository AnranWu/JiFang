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
const ll mo=998244353;

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



const int MAXN = 6e6 + 5;
ll fpow(ll a,ll b)
{
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mo;
        a=a*a%mo;
        b>>=1;
    }
    return ans;
}
ll fac[MAXN + 100], inv_fac[MAXN + 100],inv[MAXN+100];///fac是分子，inv是分母
void init() {
    fac[0] = 1;//阶乘数组 
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = fac[i - 1] * i%mo;
    }
    inv_fac[MAXN] = fpow(fac[MAXN], mo - 2);//阶乘逆元的数组 
    for (int i = MAXN - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mo;
    }
    for(int i=1;i<=MAXN;i++){//第i个数的逆元 
        inv[i]=inv_fac[i]*fac[i-1]%mo;
    }
}
ll C(ll m, ll n)///组合
{
    return fac[m] * inv_fac[m - n] % mo*inv_fac[n] % mo;
}
ll P(ll m, ll n)///排列
{
    return fac[m] * inv_fac[m - n] % mo;
}

ll C_tmp[MAXN],fac_tmp[MAXN];
void prework(){
	C_tmp[0]=1;
	for(int i=1;i<=2500000;i++){
		C_tmp[i]=C_tmp[i-1]*C(i*2,2)%mo;
	}
	fac_tmp[1]=1;
	for(int i=3;i<=5000000;i+=2){
		fac_tmp[i]=fac_tmp[i-2]*(ll)(i-1)%mo;
	}
	fac_tmp[5000000-1]=fpow(fac_tmp[5000000-1],mo-2);
	for(int i=5000000-3;i>=0;i-=2){
		fac_tmp[i]=fac_tmp[i+2]*(ll)(i+1)%mo;
	}
}

void work(){
	int n=read();
	for(int i=1;i<=n;i++){
		if(i<=n/2)printf("0 ");
		else{
			ll s1=i-1,s2=n-i;
			ll ans=C(s1,s2)*P(s2,s2)%mo;
			ans=ans*C_tmp[(s1-s2)/2]%mo;
			ans=ans*inv_fac[(s1-s2)/2]%mo;
			ans=ans*fac_tmp[n]%mo;
			printf("%lld%c",ans,i==n?'\n':' ');
		}
	}
}

int main()
{
	init();
	prework();
	int T=read();while(T--)work();
	return 0;
}

/*
预处理那里不能贴着数组for
否则会一直RE一直RE 
*/ 
