#include <bits/stdc++.h>
#define ll long long 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 
#define mp make_pair 
#define pb push_back 
#define F first 
#define S second 
using namespace std;
 
const int MAXN = 100005;
const int MAXM = 100005;
const int LN = 19;
const int mod = 1e9 + 7;


inline int64_t gilbertOrder(ll x, ll y, ll pow, ll rotate) {
   if (pow == 0) {
      return 0;
   }
   ll hpow = 1 << (pow-1);
   ll seg = (x < hpow) ? (
      (y < hpow) ? 0 : 3
   ) : (
      (y < hpow) ? 1 : 2
   );
   seg = (seg + rotate) & 3;
   const ll rotateDelta[4] = {3, 0, 0, 1};
   ll nx = x & (x ^ hpow), ny = y & (y ^ hpow);
   ll nrot = (rotate + rotateDelta[seg]) & 3;
   int64_t subSquareSize = int64_t(1) << (2*pow - 2);
   int64_t ans = seg * subSquareSize;
   int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
   ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
   return ans;
}



ll N, M, K, cur, A[MAXN],H[MAXN], LVL[MAXN], DP[LN][MAXN];
ll BL[MAXN << 1], ID[MAXN << 1], VAL[20], ANS[MAXM];
ll  d[MAXN],l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < ll > adjList[MAXN];

struct query{
   int id, l, r, lc;
   int64_t ord; 
   inline void calcOrder() {
      ord = gilbertOrder(l, r, 21, 0);
   }
}Q[100005];

inline bool operator<(const query &a, const query &b) {
   return a.ord < b.ord;
}

// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline ll lca(ll u, ll v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 
inline void check(int x,list<int> ls[],int pos,ll &res){
	// If (x) occurs twice, then don't consider it's value
	if(VIS[x]){
		if(pos==0){
			// we want to remove  from back 
			ls[A[x]].pop_back();
			if(!ls[A[x]].empty()){
				int element = ls[A[x]].back();
				if(A[element]==A[x]){
					VAL[A[x]]-=(H[element]-H[x])*(H[element]-H[x]);
					res-=(H[element]-H[x])*(H[element]-H[x]);
				}
			}
		}else{
			ls[A[x]].pop_front();
			if(!ls[A[x]].empty()){
				int element = ls[A[x]].front();
				if(A[element]==A[x]){
					VAL[A[x]]-=(H[element]-H[x])*(H[element]-H[x]);
					res-=(H[element]-H[x])*(H[element]-H[x]);
				}
			}
		}
    }
	else{
    	if(pos==0){
    		int element = -1;
    		if(!ls[A[x]].empty()){
    			element = ls[A[x]].back();
			}
			ls[A[x]].push_back(x);
			if(element!=-1){
				if(A[element]==A[x]){
					VAL[A[x]]+=(H[element]-H[x])*(H[element]-H[x]);
					res+=(H[element]-H[x])*(H[element]-H[x]);
				}
			}
		}else{
			int element = -1;
    		if(!ls[A[x]].empty()){
    			element = ls[A[x]].front();
			}
			ls[A[x]].push_front(x);
			if(element!=-1){
				if(A[element]==A[x]){
					VAL[A[x]]+=(H[element]-H[x])*(H[element]-H[x]);
					res+=(H[element]-H[x])*(H[element]-H[x]);
				}
			}
		}
    }
	VIS[x] ^= 1;
}

ll calculate(ll pos){
	ll lca_col = A[pos];
	ll ans  = 0;
	for(int i=1;i<=10;i++){
		if(i!=lca_col){
			ans+=VAL[i];
		}
	}
	return ans;
}

void compute(){
	
	// Perform standard Mo's Algorithm
	ll curL = Q[0].l, curR = Q[0].l - 1, res = 0;
	
	list<int> ls[11];
	
	for (int i = 0; i < M; i++){
		while (curL < Q[i].l) check(ID[curL++],ls,1,res);
		while (curL > Q[i].l) check(ID[--curL],ls,1,res);
		while (curR < Q[i].r) check(ID[++curR],ls,0,res);
		while (curR > Q[i].r) check(ID[curR--],ls,0,res);
		
		ANS[Q[i].id] = res-VAL[A[Q[i].lc]];
	}
 
	for (int i = 0; i < M; i++) printf("%lld\n", ANS[i]);
}

inline ll read(){
   ll val = 0; char ch;
   for(ch = getchar(); ch<'0' || ch>'9'; ch = getchar());
   for(; ch>='0' and ch<='9'; ch = getchar()) 
      val = val*10 + ch - '0';
   return val;
}


int main(){
	int t=1;
//	cin>>t;
	while(t--){
		
		cur = 0;
		
		ll u, v, x;
		
		N = read();
		
		for (int i = 1; i <= N; i++) A[i] = read(); 
		
		for (int i = 1; i <= N; i++) H[i] = read();
		
		for (int i = 1; i <= N; i++) adjList[i].clear();
		for (int i = 1; i < N; i++){
			u = read();
			v = read();
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		
		
		DP[0][1] = 1;
		dfs(1, -1);
		int size = sqrt(cur);
	
		M = read();
			
		for (int i = 0; i < M; i++){
			u = read();
			v = read();
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
			Q[i].calcOrder();
		}
	 
		sort(Q, Q + M);
		compute();	
	}
}
