
// Problem : A. Two Substrings
// Contest : Codeforces - Codeforces Round #306 (Div. 2)
// URL : https://codeforces.com/problemset/problem/550/A
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
	int n=s.length();
	int prefix[n]= {0};
	f(i,n-1){
		if(s[i]=='A' and s[i+1]=='B'){
			prefix[i] = true;
		}
	}
	f(i,n-1)prefix[i+1]+=prefix[i];
	f(i,n-1){
		if(s[i]=='B' and s[i+1]=='A'){
			if(i>1 and prefix[i-2]>0){
				cout<<"YES\n";
				return ;
			}
			if(i<n-1 and (prefix[n-1]-prefix[i+1]>0)){
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
