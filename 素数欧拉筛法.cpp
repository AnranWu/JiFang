const ll maxn=100000001;
ll prime[maxn];      //就是个素数表
bool sf[maxn];        //判断这个数是不是素数，sf[i]中的i是从1到maxn的数
void sushu()
{         //核心 欧拉筛代码
    ll num=0;        //num 用来记筛到第几个质数
    memset(sf,true,sizeof(sf));
	sf[1] = false;
    sf[0] = false;  //1 0 特判 
    for(int i = 2;i <= maxn; i ++)
	{          //外层枚举1~maxn
        if(sf[i]) prime[++num] = i;      //如果是质数就加入素数表
        for(int j = 1;j <= num;j ++)
		{       //内层枚举num以内的质数
            if(i * prime[j] > maxn) break; //筛完结束
            sf[i * prime[j]] = false;      //筛掉...
            if(i % prime[j] == 0) break;   //避免重复筛
        }
    } 
}

