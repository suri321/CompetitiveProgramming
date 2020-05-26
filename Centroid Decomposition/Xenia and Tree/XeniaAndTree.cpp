#include<bits/stdc++.h>
#define pb push_back 
#define mp make_pair 
#define ll long long 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++)

using namespace std;

const ll N = 1e5 + 5;
const int level = 20;
#define INF 10000000 
set<int> g[N];
int subtsz[N],parent[N];
int ans[N];

/* LCA and dist set up */

int depth[N]; 
int table[N][level]; 
int dis[N];
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    table[cur][0] = prev;  
    for(auto it=g[cur].begin();it!=g[cur].end();it++)
    { 
        if ((*it) != prev) 
            dfs((*it), cur); 
    } 
} 
  
void precomputeSparseMatrix(int n) 
{ 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (table[node][i-1] != -1) 
                table[node][i] = 
                    table[table[node][i-1]][i-1]; 
        } 
    } 
} 
 
int LCA(int u, int v) 
{ 
      if (depth[v] < depth[u]) 
        swap(u, v); 
  
      int diff = depth[v] - depth[u]; 
  
      for (int i=0; i<level; i++) 
        if ((diff>>i)&1) 
            v = table[v][i]; 
   
      if (u == v) 
        return u; 
      for (int i=level-1; i>=0; i--) 
        if (table[u][i] != table[v][i]) 
        { 
            u = table[u][i]; 
            v = table[v][i]; 
        } 
  
    return table[u][0]; 
}

void distance(int n){
	queue<int> q;
	bool vis[n+1] = {false};
	q.push(1);
	vis[1] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto it = g[x].begin();it!=g[x].end();it++){
			if(!vis[(*it)]){
				dis[(*it)] = dis[x] + 1;
				vis[(*it)] = true;
				q.push((*it));
			}
		}
	}
}

int dist(int u,int v){
	int lca = LCA(u,v);
	int res = dis[u] + dis[v] - 2*dis[lca];
	return res;
}

/* Centroid decomposition */
int nodes_count = 0;
void dfs1(int node,int par){
	subtsz[node] = 1;
	nodes_count++;
	for(auto it = g[node].begin();it!=g[node].end();it++){
		if((*it)!=par){
			dfs1((*it),node);
			subtsz[node]+=subtsz[(*it)];
		}
	}	
}

int dfs2(int node,int par){
	for(auto it = g[node].begin();it!=g[node].end();it++){
		if((*it)!=par){
			if(subtsz[(*it)]>nodes_count/2)
				return dfs2((*it),node);
		}
	}
	return node;
}

void decompose(int root,int par){
	nodes_count = 0;
	dfs1(root,-1);
	int centroid = dfs2(root,-1);
	if(par==-1)par = centroid;
	parent[centroid] = par;
	for(auto it = g[centroid].begin();it!=g[centroid].end();it++){
		g[(*it)].erase(centroid);
		decompose((*it),centroid);
	}
	g[centroid].clear();
}

/* Queries */
void update(int node){
	int x = node;
	while(1){
		ans[x] = min(ans[x],dist(x,node));
		if(x==parent[x])break;
		x = parent[x];
	}
}

int query(int node){
	int x = node;
	int res = INF;
	while(1){
		res = min(res,dist(x,node) + ans[x]);
		if(x==parent[x])break;
		x = parent[x];
	}
	return res;
}

void test(){
	int n,m;
	cin>>n>>m;
	f(i,n-1){
		int u,v;
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	
	dfs(1,0); 
	precomputeSparseMatrix(n);
	distance(n);
	
	decompose(1,-1);
	
	f(i,n+1)ans[i]=INF;
	update(1);
	while(m--){
		int type,node;
		cin>>type>>node;
		if(type==1){
			update(node);
		}else{
			cout<<query(node)<<"\n";
		}
	}
}
 
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		test();
	}
} 
