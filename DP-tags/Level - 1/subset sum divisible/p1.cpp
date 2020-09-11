
// Problem : C. Divisibility by Eight
// Contest : Codeforces - Codeforces Round #306 (Div. 2)
// URL : https://codeforces.com/problemset/problem/550/C
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
	bool dp[8]; 
	string sol[8];
	f(i,8)dp[i]=false,sol[i]="";
	int n = s.length();
	f(j,n){
		
		int cur = s[j]-'0';
		if(cur==8){
			cout<<"YES\n";
			cout<<"8\n";
			return ; 
		}
		int curr = cur;
		cur = cur%8;
		if(cur==0){
			cout<<"YES\n";
			cout<<"0\n";
			return ;
		}else{
			int need = 8-cur;
			if(dp[need]){
				cout<<"YES\n";
				cout<<sol[need]<<curr<<"\n";
				return ;
			}
			bool dp1[8]={false};
			f(i,8){
				if(dp[i]){
					int nxt = (i+cur)*10;
					nxt = nxt%8;
					if(!dp[nxt]){
						dp1[nxt] = true;
						sol[nxt] = sol[i];
						sol[nxt].pb('0'+curr);
					}
					
				}
			}
			f(k,8)if(dp1[k])dp[k]=true;
			dp[(cur*10)%8]=true;
			sol[(cur*10)%8] = to_string(curr);
			
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
