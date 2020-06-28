#include<bits/stdc++.h>
#define ll long long 

using namespace std;

void build(ll a[], ll v,ll tl ,ll tr, ll segt[]){
	if(tl==tr){
		segt[v] = a[tl];
	}else{
		ll tm = (tl+tr)/2;
		build(a,2*v,tl,tm,segt);
		build(a,2*v+1,tm+1,tr,segt);
		segt[v] = 0;
	}
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll add,ll segt[]){
	if(l>r)
		return ;
	if(l==tl and r==tr){
		segt[v]+=add;
	}else{
		ll tm = (tl+tr)/2;
		update(v*2,tl,tm,l,min(r,tm),add,segt);
		update(v*2+1,tm+1,tr,max(l,tm+1),r,add,segt);
	}
}

ll query(ll v,ll tl,ll tr, ll pos,ll segt[]){
	if(tl==tr)
		return segt[v];
	ll tm = (tl+tr)/2;
	if(pos<=tm)
		return segt[v] + query(2*v,tl,tm,pos,segt);
	else
		return segt[v] + query(2*v+1,tm+1,tr,pos,segt);
}

void test(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	ll segt[4*n];
	build(a,1,0,n-1,segt);
//	update(1,0,n-1,L,R,add,segt);
//	query(1,0,n-1,pos,segt);
	int qu; cin>>qu;
	while(qu--){
		int type;
		cin>>type;
		if(type==1){
			ll L,R,add;
			cin>>L>>R>>add;
			update(1,0,n-1,L,R,add,segt);
		}else{
			int pos;
			cin>>pos;
			ll ans = query(1,0,n-1,pos,segt);
			cout<<ans<<"\n";
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
