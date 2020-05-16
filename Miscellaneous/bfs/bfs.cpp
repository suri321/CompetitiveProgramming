
vector<int> adj[N]; 
int dist[N];

void bfs(int n){
	queue<int> q;
	q.push(1);
	bool vis[n+1];
	f(i,n+1)vis[i]=false;
	vis[1] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0;i<adj[x].size();i++){
			if(!vis[adj[x][i]]){
				vis[adj[x][i]]=true;
				dist[adj[x][i]] = dist[x]+1;
				q.push(adj[x][i]);
			}
		}
	}	
}

bfs(n);
