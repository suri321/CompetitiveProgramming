/*
	By Surender Kumar 
	IIT Mandi
*/


/* Credit to gfg */ 
/* C++ program for Heavy-Light Decomposition of a tree */
#include<bits/stdc++.h> 
#define ll long long 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 
#define mp make_pair 
#define pb push_back 
#define F first 
#define S second 
#define N 100001 
#define level 18
using namespace std; 


vector<pair<int,int> > trees[N];

// Update function for different type of queries, sum, min, max, xor-sum, ..  
int fun(int a,int b){
	return max(a,b);
//	return a+b;
}

/* a tree node structure. Every node has a parent, depth, 
subtree size, chain to which it belongs and a position 
in base array*/
struct treeNode 
{ 
	int par; // Parent of this node 
	int depth; // Depth of this node 
	int size; // Size of subtree rooted with this node 
	int pos_segbase; // Position in segment tree base 
	int chain; 
} node[N]; 

/* every Edge has a weight and two ends. We store deeper end */
struct Edge 
{ 
	int weight; // Weight of Edge 
	int deeper_end; // Deeper end 
} edge[N]; 

/* we construct one segment tree, on base array */
struct segmentTree 
{ 
	int base_array[N], tree[6*N]; 
} s; 

// A function to add Edges to the Tree matrix 
// e is Edge ID, u and v are the two nodes, w is weight 
void addEdge(int e, int u, int v, int w) 
{ 
	/*tree as undirected graph*/
	trees[u-1].pb(mp(v-1,e-1));
	trees[v-1].pb(mp(u-1,e-1));

	edge[e-1].weight = w; 
} 

// A recursive function for DFS on the tree 
// curr is the current node, prev is the parent of curr, 
// dep is its depth 
void dfs(int curr, int prev, int dep, int n) 
{ 
	/* set parent of current node to predecessor*/
	node[curr].par = prev; 
	node[curr].depth = dep; 
	node[curr].size = 1; 

	for (int i=0; i<trees[curr].size(); i++) 
	{ 
		int j = trees[curr][i].F;
		int e = trees[curr][i].S;
		if (j!=node[curr].par) 
		{ 
			edge[e].deeper_end = j; 

			dfs(j, curr, dep+1, n); 

			node[curr].size+=node[j].size; 
		} 
	} 
} 

// A recursive function that decomposes the Tree into chains 
void hld(int curr_node, int id, int *edge_counted, int *curr_chain, int n, int chain_heads[]) 
{ 
	if (chain_heads[*curr_chain]==-1)
		chain_heads[*curr_chain] = curr_node; 

	node[curr_node].chain = *curr_chain; 

	node[curr_node].pos_segbase = *edge_counted; 

	s.base_array[(*edge_counted)++] = edge[id].weight; 

	int spcl_chld = -1, spcl_edg_id;
	for(int i=0;i<trees[curr_node].size();i++){
		int j = trees[curr_node][i].F;
		int e = trees[curr_node][i].S;
		if (j!=node[curr_node].par) 
			if (spcl_chld==-1 || node[spcl_chld].size < node[j].size) 
				spcl_chld = j, spcl_edg_id = e;
	} 

	if (spcl_chld!=-1) 
		hld(spcl_chld, spcl_edg_id, edge_counted, curr_chain, n, chain_heads); 

	for(int i=0;i<trees[curr_node].size();i++)
	{ 
		int j = trees[curr_node][i].F;
		int e = trees[curr_node][i].S;
		if (j!=node[curr_node].par && j!=spcl_chld ) 
		{ 
			(*curr_chain)++; 
			hld(j, e, edge_counted, curr_chain, n, chain_heads); 
		} 
	} 
} 

// A recursive function that constructs Segment Tree for array[ss..se). 
// si is index of current node in segment tree st 
int construct_ST(int ss, int se, int si) 
{ 
	// If there is one element in array, store it in current node of 
	// segment tree and return 
	if (ss == se-1) 
	{ 
		s.tree[si] = s.base_array[ss]; 
		return s.base_array[ss]; 
	} 

	// If there are more than one elements, then recur for left and 
	// right subtrees and store the minimum of two values in this node 
	int mid = (ss + se)/2; 
	s.tree[si] = fun(construct_ST(ss, mid, si*2), construct_ST(mid, se, si*2+1)); 
	return s.tree[si]; 
} 

// A recursive function that updates the Segment Tree 
// x is the node to be updated to value val 
// si is the starting index of the segment tree 
// ss, se mark the corners of the range represented by si 
int update_ST(int ss, int se, int si, int x, int val) 
{ 

	if(ss > x || se <= x); 

	else if(ss == x && ss == se-1)s.tree[si] = val; 

	else
	{ 
		int mid = (ss + se)/2; 
		s.tree[si] = fun(update_ST(ss, mid, si*2, x, val), update_ST(mid, se, si*2+1, x, val)); 
	} 

	return s.tree[si]; 
} 

// A function to update Edge e's value to val in segment tree 
void change(int e, int val, int n) 
{ 
	update_ST(0, n, 1, node[edge[e].deeper_end].pos_segbase, val); 

	// following lines of code make no change to our case as we are 
	// changing in ST above 
	// Edge_weights[e] = val; 
	// segtree_Edges_weights[deeper_end_of_edge[e]] = val; 
} 

// A function to get the LCA of nodes u and v 
int depth[N]; 
int parent[N][level]; 
  
void dfs(int cur, int prev) 
{ 
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev; 
    for (int i=0; i<trees[cur-1].size(); i++) 
    { 
        if (trees[cur-1][i].F+1 != prev) 
            dfs(trees[cur-1][i].F+1, cur); 
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

/* A recursive function to get the minimum value in a given range 
	of array indexes. The following are parameters for this function. 
	st --> Pointer to segment tree 
	index --> Index of current node in the segment tree. Initially 
			0 is passed as root is always at index 0 
	ss & se --> Starting and ending indexes of the segment represented 
				by current node, i.e., st[index] 
	qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int ss, int se, int qs, int qe, int index) 
{ 
	//printf("%d,%d,%d,%d,%d\n", ss, se, qs, qe, index); 

	// If segment of this node is a part of given range, then return 
	// the min of the segment 
	if (qs <= ss && qe >= se-1) 
		return s.tree[index]; 

	// If segment of this node is outside the given range 
	if (se-1 < qs || ss > qe) 
		return 0; 

	// If a part of this segment overlaps with the given range 
	int mid = (ss + se)/2; 
	return fun(RMQUtil(ss, mid, qs, qe, 2*index), 
			RMQUtil(mid, se, qs, qe, 2*index+1)); 
} 

// Return minimum of elements in range from index qs (query start) to 
// qe (query end). It mainly uses RMQUtil() 
int RMQ(int qs, int qe, int n) 
{ 
	// Check for erroneous input values 
	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		printf("Invalid Input"); 
		return -1; 
	} 

	return RMQUtil(0, n, qs, qe, 1); 
} 

// A function to move from u to v keeping track of the maximum 
// we move to the surface changing u and chains 
// until u and v donot belong to the same 
int crawl_tree(int u, int v, int n, int chain_heads[]) 
{ 
	int chain_u, chain_v = node[v].chain, ans = 0; 

	while (true) 
	{ 
		chain_u = node[u].chain; 

		/* if the two nodes belong to same chain, 
		* we can query between their positions in the array 
		* acting as base to the segment tree. After the RMQ, 
		* we can break out as we have no where further to go */
		if (chain_u==chain_v) 
		{ 
			if (u==v); //trivial
			else
			ans = fun(RMQ(node[v].pos_segbase+1, node[u].pos_segbase, n), ans); 
			break; 
		} 

		/* else, we query between node u and head of the chain to which 
		u belongs and later change u to parent of head of the chain 
		to which u belongs indicating change of chain */
		else
		{ 
			ans = fun(ans, RMQ(node[chain_heads[chain_u]].pos_segbase, node[u].pos_segbase, n)); 
			u = node[chain_heads[chain_u]].par; 
		} 
	} 

	return ans; 
} 

// A function for MAX_EDGE query 
int Fquery(int u, int v, int n, int chain_heads[]) 
{ 
	int lca = LCA(u+1, v+1); 
	lca--;
	int ans = fun(crawl_tree(u, lca, n, chain_heads), crawl_tree(v, lca, n, chain_heads)); 
	return ans;
} 

void test(){
	f(i,N)trees[i].clear();	
	int n; // number of nodes 
	cin>>n;
	
	for(int i=1;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		addEdge(i,u,v,w);
	}
	
	int root = 0, parent_of_root=-1, depth_of_root=0; 

	dfs(root, parent_of_root, depth_of_root, n); 

	int chain_heads[N]; 

	memset(chain_heads, -1, sizeof(chain_heads)); 
	int edge_counted = 0; 
	int curr_chain = 0; 
	hld(root, n-1, &edge_counted, &curr_chain, n, chain_heads); 
	construct_ST(0, edge_counted, 1); 
	
	dfs(1,0); 
      precomputeSparseMatrix(n); 
      
      int query;
      cin>>query;
      while(query--){
      	int qtype;
      	cin>>qtype;
      	// query type 1, ans for u,v
      	if(qtype==1){
      		int u,v;
	      	cin>>u>>v;
	      	int ans = Fquery(u-1,v-1,n,chain_heads);
	      	cout<<ans<<"\n";
		}
      	else{   // query type 2 change value of edge number e to val
      		int e,val;
	      	cin>>e>>val;
	      	change(e-1, val, n);	
		}	 
	}
}

// driver function 
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		test();
	} 
} 

/*
INPUT 
1
11 
1 2 13
1 3 9
1 4 23 
2 5 4 
2 6 25
3 7 29
6 8 5 
7 9 30
8 10 1
8 11 6
6
1 11 9
2 8 28
1 11 9
1 11 4
2 5 22
1 11 4
Output :
	30
	29
	25
	23
	*/


