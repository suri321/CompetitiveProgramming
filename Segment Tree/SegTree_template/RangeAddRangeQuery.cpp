#include<bits/stdc++.h>
#define ll long long 

using namespace std;

ll base = INT_MIN; // for sum = 0, min = INT_MAX
ll func(ll a,ll b){
	return max(a,b);
}

void build(ll a[], ll v,ll tl ,ll tr, ll segt[],ll lazy[]){
	lazy[v] = 0;
	if(tl==tr){
		segt[v] = a[tl];
	}else{
		ll tm = (tl+tr)/2;
		build(a,2*v,tl,tm,segt,lazy);
		build(a,2*v+1,tm+1,tr,segt,lazy);
		segt[v] = func(segt[v*2],segt[v*2+1]);
	}
}

void push(ll v, ll segt[],ll lazy[]){
	segt[v*2]+=lazy[v];
	lazy[v*2]+=lazy[v];
	segt[v*2+1]+=lazy[v];
	lazy[v*2+1]+=lazy[v];
	lazy[v]=0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll add,ll segt[],ll lazy[]){
	if(l>r)
		return ;
	if(l==tl and r==tr){
		segt[v]+=add;
		lazy[v]+=add;
	}else{
		push(v,segt,lazy);
		ll tm = (tl+tr)/2;
		update(v*2,tl,tm,l,min(r,tm),add,segt,lazy);
		update(v*2+1,tm+1,tr,max(l,tm+1),r,add,segt,lazy);
		segt[v]= func(segt[v*2],segt[v*2+1]);
	}
}

ll query(ll v,ll tl,ll tr, ll l,ll r,ll segt[],ll lazy[]){
	if(l>r)
		return base;
	if(l<=tl and tr<=r)
		return segt[v];
	ll tm = (tl+tr)/2;
	push(v,segt,lazy);
	return func(query(2*v,tl,tm,l,min(tm,r),segt,lazy),query(2*v+1,tm+1,tr,max(l,tm+1),r,segt,lazy));
}

void test(){
	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	ll segt[4*n],lazy[4*n];
	bool marked[4*n] = {false};
	build(a,1,0,n-1,segt,lazy);
//	update(1,0,n-1,L,R,new_val,segt,marked);
//	query(1,0,n-1,pos,segt,marked);
	int qu; cin>>qu;
	while(qu--){
		int type;
		cin>>type;
		if(type==1){
			ll L,R,add;
			cin>>L>>R>>add;
			update(1,0,n-1,L,R,add,segt,lazy);
		}else{
			ll L,R; 
			cin>>L>>R;
			ll ans = query(1,0,n-1,L,R,segt,lazy);
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
