
// Problem : B. Ilya and Queries
// Contest : Codeforces - Codeforces Round #186 (Div. 2)
// URL : https://codeforces.com/problemset/problem/313/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
	string s;
	cin>>s;
	int n = s.length();
	int prefix[n+1] ;
	f(i,n+1)prefix[i] = 0;
	f(i,n-1){
		if(s[i]==s[i+1]){
			prefix[i+1] = 1;
		}
	}
	f(i,n)prefix[i+1] = prefix[i+1] + prefix[i];
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		int ans = prefix[r-1]-prefix[l-1];
		cout<<ans<<"\n";
	}
}


int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
