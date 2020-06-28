#include<bits/stdc++.h>
#define ll long long 
#define f(i,n) for(int i=0;i<n;i++) 

using namespace std;

ll func(ll a, ll b){
	return a+b;
}

void build(ll a[],ll v,ll tl,ll tr, ll segt[]){
	if(tl==tr)
		segt[v] = a[tl];
	else{
		ll tm = (tl+tr)/2;
		build(a,v*2,tl,tm,segt);
		build(a,v*2+1,tm+1,tr,segt);
		segt[v] = func(segt[2*v] , segt[2*v + 1]);
	}
}

ll query(ll segt[], ll v, ll tl, ll tr, ll l, ll r){
	if(l>r)
		return 0;
	if(tl==l and tr==r)
		return segt[v];
	else{
		ll tm = (tl+tr)/2;
		return func(query(segt, 2*v, tl, tm, l, min(r,tm)) , 
			query(segt, 2*v+1, tm+1,tr,max(l,tm+1) ,r));
	}
}

void update(ll segt[],ll v, ll tl, ll tr, ll pos, ll new_val){
	if(tl==tr){
		segt[v] = new_val;
	}else{
		ll tm = (tl + tr)/2;
		if(pos<=tm)
			update(segt,2*v,tl,tm,pos,new_val);
		else
			update(segt,2*v+1,tm+1,tr,pos,new_val);
		segt[v] = func(segt[2*v] , segt[2*v + 1]);
	}
}

void test(){
	ll n;
	cin>>n;
	ll a[n];
	f(i,n)cin>>a[i];
	ll segt[n*4];
	ll v=1,tl=0,tr=n-1;
	build(a,v,tl,tr,segt);
//	query(segt,1,0,n-1,L,R);
//	update(segt,1,0,n-1,pos,new_val);

	int q;
	cin>>q;
	while(q--){
		int type; cin>>type;
		if(type==1){
			ll l, r;
			cin>>l>>r;
			// if 1 indexed, l--,r--;
			ll ans = query(segt,1,0,n-1,l,r);
			cout<<ans<<"\n";
		}else{
			ll pos,val;
			cin>>pos>>val;
			update(segt,1,0,n-1,pos,val);
			a[pos] = val;
			f(i,n)cout<<a[i]<<" ";cout<<"\n";
		}
	}

}

int main(){
	int tests=1;
	cin>>tests;
	while(tests--){
		test();
	}
}
