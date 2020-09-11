
// Problem : A. Boredom
// Contest : Codeforces - Codeforces Round #260 (Div. 1)
// URL : https://codeforces.com/problemset/problem/455/A
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
	int n;
	cin>>n;
	int a[n];
	f(i,n)cin>>a[i];
	ll freq[100005]={0};
	f(i,n)freq[a[i]]++;
	ll dp[100005] = {0};
	for(ll i=1;i<100005;i++){
		dp[i] = max(freq[i]*i + dp[i-2], dp[i-1]);
	}
	cout<<dp[100000]<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
