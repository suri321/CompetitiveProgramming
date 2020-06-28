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

void push(ll v, ll segt[],bool marked[]){
	if(marked[v]){
		segt[v*2] = segt[v*2+1] = segt[v];
		marked[v*2] = marked[v*2+1] = true;
		marked[v] = false;
	}
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll new_val,ll segt[],bool marked[]){
	if(l>r)
		return ;
	if(l==tl and r==tr){
		segt[v]=new_val;
		marked[v] = true;
	}else{
		push(v,segt,marked);
		ll tm = (tl+tr)/2;
		update(v*2,tl,tm,l,min(r,tm),new_val,segt,marked);
		update(v*2+1,tm+1,tr,max(l,tm+1),r,new_val,segt,marked);
	}
}

ll query(ll v,ll tl,ll tr, ll pos,ll segt[],bool marked[]){
	if(tl==tr)
		return segt[v];
	ll tm = (tl+tr)/2;
	push(v,segt,marked);
	if(pos<=tm)
		return query(2*v,tl,tm,pos,segt,marked);
	else
		return query(2*v+1,tm+1,tr,pos,segt,marked);
}

void test(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	ll segt[4*n];
	bool marked[4*n] = {false};
	build(a,1,0,n-1,segt);
//	update(1,0,n-1,L,R,new_val,segt,marked);
//	query(1,0,n-1,pos,segt,marked);
	int qu; cin>>qu;
	while(qu--){
		int type;
		cin>>type;
		if(type==1){
			ll L,R,new_val;
			cin>>L>>R>>new_val;
			update(1,0,n-1,L,R,new_val,segt,marked);
		}else{
			int pos;
			cin>>pos;
			ll ans = query(1,0,n-1,pos,segt,marked);
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
