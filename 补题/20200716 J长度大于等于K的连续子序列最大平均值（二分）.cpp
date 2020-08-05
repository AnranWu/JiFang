#include<iostream>
#include<cstdio>
#define fo(i,j,n) for(register int i=j; i<=n; ++i)
#define ll long long
using namespace std;
const int maxn = 1e5;
int n,F;
double a[maxn+5],b[maxn+5],sum[maxn+5];
// b����Ϊa�����ȥƽ����mid������ֻҪĳһ�κͷǸ���˵��ƽ��������mid 
// �� b ���ȴ���F���Ӵ��ͷǸ� 
bool ok(double mid){
	fo(i,1,n) b[i]=a[i]-mid;
	// b ǰ׺�� 
	fo(i,1,n){
		sum[i] = sum[i-1] + b[i];
	}
	double min_val = 1e10,ans=-1e10;
	fo(i,F,n){
		min_val = min(sum[i-F], min_val); // ǰ�棨0~i-F������Сǰ׺�� 
		ans = max(ans, sum[i]-min_val);
	}
	return ans>=0;
}
void solve(){
	double l=-1,r=2000,eps=1e-4; // 2��ƽ���� ,epsһ��Ҫ����Ŀ��ȷ�ȴ󣬱���1e-3,����ȡ1e-5 
	while(r-l>eps){
		double mid = (l+r)/2;
		if(ok(mid)) l=mid;
		else r=mid;
	}
	cout<<int(r*1000)<<endl; // ����ʵ����ȡ�Ͻ�(����ȷ��С����Ŀ��ȷ�ȵ�ʱ��L���Ե�ʱ��RҲ�ض�����,ȡ���ȡR) 
}
int main(){
	while(scanf("%d%d",&n,&F)==2){	
		fo(i,1,n)scanf("%lf",&a[i]);
		solve();
	}
	return 0;
} 

