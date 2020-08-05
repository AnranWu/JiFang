#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
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
 
int main()
{
    lll a = read();
    write(a);
    return 0;
}

