vector<int> adj[N];
int depth[N]; 
int parent[N][level]; 
 
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<adj[cur].size(); i++) 
    { 
        if (adj[cur][i] != prev) 
            dfs(adj[cur][i], cur); 
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

int kthancestor(int V, int k) 
{ 
    // Doing bitwise operation to 
    // check the set bit 
    for (int i = 0; i <= level; i++) 
    { 
        if (k & (1 << i)) 
        { 
            V = parent[V][i]; 
            if (V == -1) 
                break; 
        } 
    } 
    return V; 
} 
 
 
dfs(1,0); 
precomputeSparseMatrix(n);
LCA(u,v);
kthancestor(node,k);
