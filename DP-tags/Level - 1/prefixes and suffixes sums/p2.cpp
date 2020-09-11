
// Problem : A. QAQ
// Contest : Codeforces - Codeforces Round #447 (Div. 2)
// URL : https://codeforces.com/problemset/problem/894/A
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
	string s;
	cin>>s;
	int n = s.length();
	int prefix[n+1];
	f(i,n+1)prefix[i] = 0;
	f(i,n){
		if(s[i]=='Q')prefix[i+1] = 1;
	}
	f(i,n)prefix[i+1] = prefix[i] + prefix[i+1];
	int ans = 0;
	f(i,n){
		if(s[i]=='A'){
			ans = ans + (prefix[i]*(prefix[n]-prefix[i]));
		}
	}
	cout<<ans<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
