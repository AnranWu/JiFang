#include<iostream>
#include<cstdio>
#define fo(i,j,n) for(register int i=j; i<=n; ++i)
#define ll long long
using namespace std;
const int maxn = 1e5;
int n,F;
double a[maxn+5],b[maxn+5],sum[maxn+5];
// b数组为a数组减去平均数mid，所以只要某一段和非负即说明平均数大于mid 
// 求 b 长度大于F的子串和非负 
bool ok(double mid){
	fo(i,1,n) b[i]=a[i]-mid;
	// b 前缀和 
	fo(i,1,n){
		sum[i] = sum[i-1] + b[i];
	}
	double min_val = 1e10,ans=-1e10;
	fo(i,F,n){
		min_val = min(sum[i-F], min_val); // 前面（0~i-F）的最小前缀和 
		ans = max(ans, sum[i]-min_val);
	}
	return ans>=0;
}
void solve(){
	double l=-1,r=2000,eps=1e-4; // 2分平均数 ,eps一定要比题目精确度大，本题1e-3,可以取1e-5 
	while(r-l>eps){
		double mid = (l+r)/2;
		if(ok(mid)) l=mid;
		else r=mid;
	}
	cout<<int(r*1000)<<endl; // 二分实数，取上界(当精确度小于题目精确度的时候L可以的时候R也必定可以,取大故取R) 
}
int main(){
	while(scanf("%d%d",&n,&F)==2){	
		fo(i,1,n)scanf("%lf",&a[i]);
		solve();
	}
	return 0;
} 

