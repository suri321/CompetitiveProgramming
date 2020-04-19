#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define pb push_back 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 

using namespace std;

#define MAXN 100001
#define K 25
ll st[MAXN][K + 1];
int lg[MAXN+1];
ll fun(ll x,ll y){
	return __gcd(x,y);
}

void precompute(ll array[],int N){
	for (int i = 0; i < N; i++)
    	st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
    	for (int i = 0; i + (1LL << j) <= N; i++)
        	st[i][j] = fun(st[i][j-1], st[i + (1LL << (j - 1))][j - 1]);
        	
    lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
    	lg[i] = lg[i/2] + 1;
}


ll binsearch(ll x,ll n,ll g,ll i){
	ll low = x,high = n-1;
	
	ll ans = x;
	while(low<high){
		ll mid = low + (high-low)/2;
		
		int j = lg[mid - i + 1];
		int gg = fun(st[i][j], st[mid - (1 << j) + 1][j]);
		if(gg<g){
			high = mid;
		}
		else{
			ans = mid;
			low = mid+1;
		}
	}
	return ans;
}

void test(){
	ll n;
	cin>>n;
	ll a[n];
	f(i,n)cin>>a[i];
	precompute(a,n);
	
	unordered_map<ll,ll> map1;
	
	f(i,n){
		ll start = i;
		ll g = a[start];
		while(start<n){
			ll in = binsearch(start,n,g,i);
			map1[g]+=(in-start+1);
			start = in+1LL;
			if(start<n)
				g = __gcd(g,a[start]);
		}	
	}
	
	int q;
	cin>>q;
	while(q--){
		ll x;
		cin>>x;
		cout<<map1[x]<<"\n";	
	}
	
}

int main(){
	int t=1;
//	cin>>t;
	while(t--){
		test();
	}
}
