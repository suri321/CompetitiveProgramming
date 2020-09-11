
// Problem : B. Mashmokh and ACM
// Contest : Codeforces - Codeforces Round #240 (Div. 1)
// URL : https://codeforces.com/problemset/problem/414/B
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

void test(){
	int n,k;
	cin>>n>>k;
	ll dp[k][n];
	f(i,n)dp[0][i] = 1LL;
	for(int i=1;i<k;i++){
		for(int j=1;j<=n;j++){
			ll ans = 0;
			for(int k=1;k*k<=j;k++){
				if(j%k==0){
					ans = (ans + dp[i-1][k-1])%mod;
					if((j/k)!=k){
						ans = (ans + dp[i-1][j/k - 1])%mod;
					}
				}
			}
			dp[i][j-1] = ans;
		}
	}
	ll ans = 0;
	f(i,n)ans = (ans + dp[k-1][i])%mod;
	cout<<ans<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
