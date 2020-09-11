
// Problem : A. Army
// Contest : Codeforces - School Personal Contest #1 (Winter Computer School 2010/11) - Codeforces Beta Round #38 (ACM-ICPC Rules)
// URL : https://codeforces.com/problemset/problem/38/A
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
	int n;
	cin>>n;
	int a[n];
	a[0] = 0;
	f(i,n-1)cin>>a[i+1];
	f(i,n-1)a[i+1]+=a[i];
	int x,y;
	cin>>x>>y;
	cout<<a[y-1]-a[x-1]<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
