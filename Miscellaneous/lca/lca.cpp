vector<int> adj[N];
int depth[N]; 
int parent[N][level]; 
 
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<adj[cur-1].size(); i++) 
    { 
        if (adj[cur-1][i]+1 != prev) 
            dfs(adj[cur-1][i]+1, cur); 
    } 
} 
  
void precomputeSparseMatrix(int n) 
{ 
    for (int i=1; i<level; i++) 
    { 
        for (int node = 1; node <= n; node++) 
        { 
            if (parent[node][i-1] != -1) 
                parent[node][i] = 
                    parent[parent[node][i-1]][i-1]; 
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
            v = parent[v][i]; 
   
    if (u == v) 
        return u; 
    for (int i=level-1; i>=0; i--) 
        if (parent[u][i] != parent[v][i]) 
        { 
            u = parent[u][i]; 
            v = parent[v][i]; 
        } 
  
    return parent[u][0]; 
}
 
 
dfs(1,0); 
precomputeSparseMatrix(n);
