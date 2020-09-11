
// Problem : B. Fence
// Contest : Codeforces - Codeforces Round #211 (Div. 2)
// URL : https://codeforces.com/problemset/problem/363/B
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
	int n,k;
	cin>>n>>k;
	ll a[n];
	f(i,n)cin>>a[i];
	int prefix[n+1]={0};
	f(i,n)prefix[i+1] = prefix[i] + a[i];
	int mini = prefix[k];
	for(int i=k;i<=n;i++){
		mini = min(mini,prefix[i]-prefix[i-k]);
	}
	for(int i=k;i<=n;i++){
		if(prefix[i]-prefix[i-k]==mini){
			cout<<i-k+1<<"\n";
			return ;
		}
	}
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
