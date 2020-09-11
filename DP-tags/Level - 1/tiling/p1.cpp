
// Problem : D. Flowers
// Contest : Codeforces - Codeforces Round #271 (Div. 2)
// URL : https://codeforces.com/problemset/problem/474/D
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define f(i,n) for(int i=0;i<n;i++) 
#define F first 
#define S second 
#define pb push_back 

using namespace std;

const int mod = 1e9 + 7;

const int N = 100005;
ll dp[N];
ll prefix[N];
void fun(int k){
	// cout<<k<<"\n";
	for(int i=0;i<k;i++){
		dp[i] = 1;
	}
	for(int i=k;i<N;i++){
		dp[i] = (dp[i-1] + dp[i-k])%mod;
	}
	prefix[1] = dp[1];
	for(int i=2;i<N;i++){
		prefix[i] = (prefix[i-1] + dp[i])%mod;
	}
}

void test(){
	int a,b;
	cin>>a>>b;
	// cout<<a<<" "<<b<<"\n";
	cout<<(prefix[b]-prefix[a-1]+mod)%mod<<"\n";
}

int main(){
	int tests=1;
	cin>>tests;
	int k;
	cin>>k;
	fun(k);
	while(tests--){
		test();
	}
}
