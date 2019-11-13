#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll mod=1e9+7;

int main(){
	int t,k;
	cin>>t>>k;
	ll dp[100001];
	dp[0]=1;
	dp[1]=1;
	if(k==1)dp[1]++;
	for(int i=2;i<=100000;i++){
		int temp=(i-k);
		dp[i]=dp[i-1];
		if(temp>=0)
			dp[i]+=dp[temp];
		dp[i]=dp[i]%mod;
	}
	ll prefix[100001];
	prefix[0]=0;
	for(int i=1;i<=100000;i++){
		prefix[i]=prefix[i-1]+dp[i];
		prefix[i]=prefix[i]%mod;	
	}
		
	while(t-->0){
		int l,r;
		cin>>l>>r;
		ll ans=(prefix[r]-prefix[l-1]+mod)%mod;
		cout<<ans<<"\n";
	}
}
