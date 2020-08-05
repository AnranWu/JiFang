const int MAXN = 6e6 + 5;
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
