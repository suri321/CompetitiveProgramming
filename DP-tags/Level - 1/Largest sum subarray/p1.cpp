
// Problem : A. Flipping Game
// Contest : Codeforces - Codeforces Round #191 (Div. 2)
// URL : https://codeforces.com/problemset/problem/327/A
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
	int sum = 0;
	f(i,n)sum+=a[i];
	f(i,n)if(a[i]==0)a[i]=-1;
	f(i,n)a[i] = a[i]*-1;
	
	/* largest sum subarray */
	int ans = 0,s=0;
	f(i,n){
		s = max(s+a[i],a[i]);
		ans = max(ans,s);
	}
	
	// special case 
	if(ans==0)ans--;
	
	cout<<ans+sum<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
