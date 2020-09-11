
// Problem : A. Cut Ribbon
// Contest : Codeforces - Codeforces Round #119 (Div. 2)
// URL : https://codeforces.com/contest/189/problem/A
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

void test(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int dp[5005];
	f(i,n+1)dp[i] = -1e5;
	
	dp[a] = 1, dp[b] = 1, dp[c] = 1;
	f(i,n+1){
		int &ans = dp[i];
		if(i-a>=0){
			ans = max(ans,dp[i-a]+1);
		}
		if(i-b>=0){
			ans = max(ans,dp[i-b]+1);
		}
		if(i-c>=0){
			ans = max(ans,dp[i-c]+1);
		}
	} 
	cout<<dp[n]<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
