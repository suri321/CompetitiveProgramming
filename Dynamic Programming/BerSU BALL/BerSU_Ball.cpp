#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	int boys[n];
	for(int i=0;i<n;i++)cin>>boys[i];
	cin>>m;
	int girls[m];
	for(int i=0;i<m;i++)cin>>girls[i];
	sort(boys,boys+n);
	sort(girls,girls+m);
	// dp[i][j] represents the subproblem or solution to boys[0...i-1] and girls[0...j-1] 
	// can be thought as a variation of LCS
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
