
// Problem : B. BerSU Ball
// Contest : Codeforces - Codeforces Round #277.5 (Div. 2)
// URL : https://codeforces.com/problemset/problem/489/B
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
	cin>>n;
	int boys[n];
	for(int i=0;i<n;i++)cin>>boys[i];
	cin>>m;
	int girls[m];
	for(int i=0;i<m;i++)cin>>girls[i];
	sort(boys,boys+n);
	sort(girls,girls+m);
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(abs(boys[i-1]-girls[j-1])<=1){
				dp[i][j]=1+dp[i-1][j-1];
			}else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m]<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
