
// Problem : B. Sereja and Suffixes
// Contest : Codeforces - Codeforces Round #215 (Div. 2)
// URL : https://codeforces.com/problemset/problem/368/B
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
	int n,m;
	cin>>n>>m;
	int a[n];
	f(i,n)cin>>a[i];
	int dp[n]={0};
	set<int> st;
	for(int i=n-1;i>=0;i--){
		st.insert(a[i]);
		dp[i] = (int)st.size();
	}
	while(m--){
		int l;
		cin>>l;
		cout<<dp[l-1]<<"\n";
	}
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
