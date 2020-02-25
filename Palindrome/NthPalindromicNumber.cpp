#include<bits/stdc++.h>
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 
#define F first 
#define S second 
#define pb push_back 
#define mp make_pair 
#define ll long long 
using namespace std;

vector<int> fun(int n){
 	string s = to_string(n);
 	vector<int> v;
	int in,jn;
 	f(i,s.length())v.pb(s[i]-'0');
	vector<int> sol = v;
	if(v.size()==1){
		sol[0]--;
	}
	else if(sol[0]==1 and sol[1]==0){
		sol[0]=0;
		sol[1]=9;
		for(jn = v.size(),in=v.size()-2;in>=1;in--,jn++){
			if(jn>=sol.size())sol.pb(sol[in]);
			else sol[jn] = sol[in];
		}
	}
	else if(sol[0]==1){
		sol[0]=0;
		for(jn = v.size(),in=v.size()-1;in>=1;in--,jn++){
			if(jn>=sol.size())sol.pb(sol[in]);
			else sol[jn] = sol[in];
		}
	}else{
		sol[0]--;
		for(jn = v.size(),in=v.size()-2;in>=0;in--,jn++){
			if(jn>=sol.size())sol.pb(sol[in]);
			else sol[jn] = sol[in];
		}
	}
	return sol;
}

int main(){
	int n;
	cin>>n;
	vector<int> num = fun(n);
	if(num[0]==0)num.erase(num.begin());
	f(i,num.size())cout<<num[i];
}
