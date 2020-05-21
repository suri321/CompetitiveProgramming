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



ll N, M, K, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
ll BL[MAXN << 1], ID[MAXN << 1], VAL[1000002], ANS[MAXM];
ll  d[MAXN],l[MAXN], r[MAXN];
bool VIS[MAXN];
vector< pair<ll,ll> > pr_lst[1000002];
vector < ll > adjList[MAXN];
vector<ll> pr;
#define MX 2000006 

void sieve()
{
   for(int i = 2; i < 1000002; i++) 
   {
      if (d[i] == 0) 
      {
         d[i] = i;
         pr.push_back(i);
      }
      for(auto x : pr)
      {
         if (x > d[i] || x * i > 1000002)
            break;
         d[i * x] = x;
      }
   }
}

ll mult(ll a,ll b){return (1ll*a*b)%mod;}
ll inv[MX];

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
 
inline void check(int x, ll& res){
	// If (x) occurs twice, then don't consider it's value
	if(VIS[x]){
      ll temp = A[x];
     for(pair<ll,ll> & pp: pr_lst[temp]){
       res = (res * inv[VAL[pp.first]+1]) % mod;
       VAL[pp.first] -= pp.second;
       res = (res * (VAL[pp.first]+1))%mod;
     }
   }
   else {
      ll temp = A[x];
      for(pair<ll,ll> & pp: pr_lst[temp]){
       res = (res * inv[VAL[pp.first]+1]) % mod;
       VAL[pp.first] += pp.second;
       res = (res * (VAL[pp.first]+1))%mod;
     }
     }
	VIS[x] ^= 1;
}
 
void compute(){
	
	// Perform standard Mo's Algorithm
	ll curL = Q[0].l, curR = Q[0].l - 1, res = 1LL;
		
	for (int i = 0; i < M; i++){
//		cout<<Q[i].l<<" "<<Q[i].r<<"\n";
		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);
		
		ll u = ID[curL], v = ID[curR];
		
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
		
		ANS[Q[i].id] = res;
		
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
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
	sieve();
	inv[1] = 1;
    for (ll i = 2; i < MX; i++) {
        inv[i] = mult(inv[mod % i], mod - mod / i);
    }
	for(ll i=2;i<1000001;i++){
    	ll temp = i;
	    while(temp!=1){
	        ll cur = d[temp],cnt = 0;
	        while(d[temp] == cur) temp/=cur,cnt++;
	        pr_lst[i].emplace_back(cur,cnt);
	    }
	}
	int t;
	cin>>t;
	while(t--){
		
		ll u, v, x;
		
		N = read();
		for (int i = 1; i <= N; i++) adjList[i].clear();
		for (int i = 1; i < N; i++){
			u = read();
			v = read();
//			scanf("%ld %ld", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
			
			// Cleanup
		cur = 0;
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
			
			// Inputting Values
		for (int i = 1; i <= N; i++) A[i] = read(); //scanf("%ld", &A[i]);
			
			// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int size = sqrt(cur);
	
//		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / size + 1;
		
		M = read();
//		scanf("%ld",&M);
			
		for (int i = 0; i < M; i++){
			u = read();
			v = read();
//			scanf("%ld %ld", &u, &v);
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
