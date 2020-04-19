#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define pb push_back 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 

using namespace std;

void dijkstra(ll dist[],set<pair<ll,ll> > st,vector<pair<ll,ll> > adj[],int n,int parent[]){
	while(!st.empty()){
		auto it = st.begin();
		pair<ll,ll> p = (*it);
		st.erase(it);
		ll dis = p.F;
		ll x = p.S;
		f(j,adj[x].size()){
			int ver = adj[x][j].F;
			int dis2 = adj[x][j].S;
			if(dist[ver]>dis+dis2){
				parent[ver] = x;
				it = st.find({dist[ver],ver});
				st.erase(it);
				dist[ver]=dis+dis2;
				st.insert({dis+dis2,ver});
			}
		}
	}
}

void test(){
	int n,m;
	cin>>n>>m;
	vector<pair<ll,ll> > adj[n+1];
	f(i,m){
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	
	
	ll max_dis = 1000000000000 ;
	ll dist[n+1];
	f(i,n+1)dist[i]=max_dis;
	dist[1]=0;
	
	
	
	set<pair<ll,ll> >  st;
	fr(i,1,n+1){
		st.insert({dist[i],i});
	}
	
	
	int parent[n+1];
	parent[1]=1;
	dijkstra(dist,st,adj,n,parent);
	
	if(dist[n]==max_dis)cout<<"-1\n";
	else{
		vector<int> ans;
		ans.pb(n);
		int x = n;
		while(parent[x]!=x){
			ans.pb(parent[x]);
			x = parent[x];
		}
		reverse(ans.begin(),ans.end());
		f(i,ans.size())cout<<ans[i]<<" ";
		cout<<"\n";
	}
	
}

int main(){
	int t=1;
//	cin>>t;
	while(t--){
		test();
	}
}
