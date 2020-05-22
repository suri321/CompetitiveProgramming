#include <cstdio>
#include <algorithm>
#include<bits/stdc++.h>
#define ll long long 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 
#define mp make_pair 
#define pb push_back 
#define F first 
#define S second 
#define N 311111
#define A 1111111
#define BLOCK 555 // ~sqrt(N)
using namespace std;

ll cnt[A], a[N], ans[N], answer = 0;
vector <ll> adj[N];
struct node {
	int L, R, i, count;
}q[N];
vector<int> po;

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}



int getSum(int BITree[], int index) 
{ 
    int sum = 0; 
    index = index + 1; 
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void updateBIT(int BITree[], int n, int index, int val) 
{ 
    index = index + 1; 
  
    while (index <= n) 
    { 
    	BITree[index] += val; 
    	index += index & (-index); 
    } 
} 
 
int *constructBITree(int n) 
{ 
    int *BITree = new int[n+1]; 
    for (int i=1; i<=n; i++) 
        BITree[i] = 0; 

    return BITree; 
} 


 //= constructBITree(n);


// modify answer and cnt in add and remove 

void add(int position,int *BITree) {
//	cout<<"Add "<<position<<"\n";
	int x = cnt[a[po[position]]];
	if(x!=0){
		updateBIT(BITree,100000,x,-1);
	}
	
	cnt[a[po[position]]]++;
	x = cnt[a[po[position]]];
	updateBIT(BITree,100000,x,1);
}

void remove(int position,int *BITree) {
	int x = cnt[a[po[position]]];
	updateBIT(BITree,100000,x,-1);
	cnt[a[po[position]]]--;
	x = cnt[a[po[position]]];
	if(x!=0){
		updateBIT(BITree,100000,x,1);
	}
}

void preorder(vector<int> &v, bool vis[], int s){
	vis[s]=true;
	v.pb(s);
	f(i,adj[s].size()){
		if(!vis[adj[s][i]])
			preorder(v,vis,adj[s][i]);
	}
}
int count1[N];

void numberOfNodes(int s, int e) 
{ 
    count1[s] = 1; 
    for(int i=0;i<adj[s].size();i++){
    	if(adj[s][i]==e)continue;
    	numberOfNodes(adj[s][i],s);
    	count1[s]+=count1[adj[s][i]];
	}
} 



int main() {
	
	int n,query;
	scanf("%d %d", &n, &query);
	f(i,n)scanf("%d",&a[i+1]);
	f(i,n-1){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bool vis[n+1] = {false};
	
	preorder(po,vis,1);
	
	
	int ID[n+1];
	f(i,po.size())ID[po[i]]=i;
	
	numberOfNodes(1, 0);
	
//	f(i,n)cout<<count1[i+1]<<" ";cout<<"\n";
	
	
	for(int i=0; i<query; i++) {
		int y,z;
		scanf("%d%d", &y, &z);
		q[i].L = ID[y];
		q[i].R = q[i].L + count1[y] - 1;
		q[i].count = z;
		q[i].i = i;
	}

	
	sort(q, q + query, cmp);


	int *BITree = constructBITree(100001);
	int currentL = 0, currentR = 0;
	for(int i=0; i<query; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL > L) {
			add(currentL-1,BITree);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR,BITree);
			currentR++;
		}
		while(currentL < L) {
			remove(currentL,BITree);
			currentL++;
		}
		while(currentR > R+1) {
			remove(currentR-1,BITree);
			currentR--;
		}
		ll tot = getSum(BITree, 100000);
		ll rem = getSum(BITree, q[i].count-1);
		
		ans[q[i].i] = tot-rem; 
	}

	f(i,query)cout<<ans[i]<<"\n";
}
