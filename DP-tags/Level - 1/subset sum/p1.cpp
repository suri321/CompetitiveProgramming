
// Problem : C. k-Tree
// Contest : Codeforces - Codeforces Round #247 (Div. 2)
// URL : https://codeforces.com/problemset/problem/431/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define f(i,n) for(int i=0;i<n;i++) 
#define F first 
#define S second 
#define pb push_back 

using namespace std;

ll mod = 1e9 + 7;

ll cache[101][2];
ll d,k;
ll dp(ll sum, int use){
	if(sum<0)return 0;
	if(cache[sum][use]!=-1)
		return cache[sum][use];
	if(use==0 and sum==0)
		return 1;
	if(use==1 and sum<d)
		return 0;
	if(use==0){
		ll ans = 0;
		for(int i=1;i<=min(k,sum);i++){
			ans = (ans + dp(sum-i,use))%mod;
		}
		cache[sum][use] = ans;
		return ans;
	}else{
		ll ans = 0;
		for(int i=1;i<d;i++){
			ans = (ans + dp(sum-i,use))%mod;
		}
		for(int i=d;i<=k;i++){
			ans = (ans + dp(sum-i,1-use))%mod;
		}
		cache[sum][use] = ans;
		return ans;
	}
}


void test(){
	ll n;
	cin>>n>>k>>d;
	f(i,101)cache[i][0]=-1LL,cache[i][1] = -1LL;
	cout<<dp(n,1)<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
