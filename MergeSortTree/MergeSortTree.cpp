// Find the smallest number greater or equal to a specified number. No modification queries

#include<bits/stdc++.h>
#define ll long long 
#define f(i,n) for(int i=0;i<n;i++) 

using namespace std;

const ll INF = 1e18;

void build(ll a[],ll v,ll tl,ll tr, vector<ll> MergeSTree[]){
	if(tl==tr)
		MergeSTree[v] = vector<ll> (1,a[tl]);
	else{
		ll tm = (tl+tr)/2;
		build(a,v*2,tl,tm,MergeSTree);
		build(a,v*2+1,tm+1,tr,MergeSTree);
		merge(MergeSTree[2*v].begin(),MergeSTree[2*v].end(),MergeSTree[v*2 +1].begin(),MergeSTree[v*2 +1].end(),back_inserter(MergeSTree[v]));
	}
}

ll query(vector<ll> MergeSTree[], ll v, ll tl, ll tr, ll l, ll r, ll x){
	if(l>r)
		return INF;
	if(tl==l and tr==r)
	{
		vector<ll> ::iterator pos = lower_bound(MergeSTree[v].begin(),MergeSTree[v].end(),x);
		if(pos!=MergeSTree[v].end()){
			return *pos;
		}
		return INF;
	}
	else{
		ll tm = (tl+tr)/2;
		return min(query(MergeSTree, 2*v, tl, tm, l, min(r,tm),x) , 
			query(MergeSTree, 2*v+1, tm+1,tr,max(l,tm+1) ,r,x));
	}
}

void test(){
	ll n;
	cin>>n;
	ll a[n];
	f(i,n)cin>>a[i];
	vector<ll> MergeSTree[n*4];
	ll v=1,tl=0,tr=n-1;
	build(a,v,tl,tr,MergeSTree);
//	query(MergeSTree,1,0,n-1,L,R,x);

	int q;
	cin>>q;
	while(q--){
		ll L,R,x;
		cin>>L>>R>>x;
		ll res = query(MergeSTree,1,0,n-1,L,R,x);
		if(res==INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}

}

int main(){
	int tests=1;
	cin>>tests;
	while(tests--){
		test();
	}
}
