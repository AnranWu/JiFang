const int MAXN = 6e6 + 5;
ll fac[MAXN + 100], inv_fac[MAXN + 100],inv[MAXN+100];///fac�Ƿ��ӣ�inv�Ƿ�ĸ
void init() {
    fac[0] = 1;//�׳����� 
    for (int i = 1; i <= MAXN; i++) {
        fac[i] = fac[i - 1] * i%mo;
    }
    inv_fac[MAXN] = fpow(fac[MAXN], mo - 2);//�׳���Ԫ������ 
    for (int i = MAXN - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % mo;
    }
    for(int i=1;i<=MAXN;i++){//��i��������Ԫ 
        inv[i]=inv_fac[i]*fac[i-1]%mo;
    }
}
ll C(ll m, ll n)///���
{
    return fac[m] * inv_fac[m - n] % mo*inv_fac[n] % mo;
}
ll P(ll m, ll n)///����
{
    return fac[m] * inv_fac[m - n] % mo;
}
