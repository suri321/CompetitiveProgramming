#include<bits/stdc++.h>
#define pb push_back 
#define mp make_pair 
#define ll long long 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++)
 
#define N 3 
using namespace std;
 
ll mod = 1e9+7;
ll mod2 = 1e9 + 6;

ll F[N][N];
ll P[N][N];
ll B[N];
 
ll k;

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1LL; 
    x = x % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1;
        x = (x*x) % p;   
    } 
    return res; 
}

ll gcdExtended(ll a, ll b, ll *x, ll *y); 

ll modInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 
    ll res = (x%m + m) % m; 
    return res;
}  
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{  
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);  
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 

void multiply(ll a[N][N],ll b[N][N]){
	ll res[N][N];
	f(i,k){
		f(j,k){
			ll temp = 0;
			f(p,k){
				temp=(temp+(a[i][p]*b[p][j])%mod2)%mod2;
			}
			res[i][j]=temp;
		}
	}
	f(i,k)f(j,k)a[i][j]=res[i][j];
}
 
void power(ll P[N][N],ll n){
	if(n<=0 or n==1)
		return ;
	power(P,n/2);
	multiply(P,P);
	if(n%2!=0){
		multiply(P,F);
	}
}
 
void solve(ll n){
	power(P,n-k);
}

// to calculate 1/(a^b) %m 
ll moPow(ll a, ll b){
	if(b==0)
		return 1LL;
	ll res = 1LL;
	ll x = moPow(a,b/2);
	res = (x*x)%mod;
	if(b%2!=0)
		res = (res*modInverse(a,mod))%mod;
	return res;
}

void test(){
	k=3;
	ll c[k];
	f(i,k)c[i]=1; 
	ll n;
	cin>>n;
	f(i,N)f(j,N)F[i][j]=0;
	f(j,k)F[0][j]=c[j];
	fr(i,1,k){
		F[i][i-1]=1;
	}
	f(i,N)f(j,N)P[i][j]=F[i][j];
	solve(n);
	
	ll f1,f2,f3,cc;
	cin>>f1>>f2>>f3>>cc;
	
	ll cs = cc;
	
	unordered_map<ll,ll> m1,m2,m3,m4;
	
	for(int i=2;i*i<=f1;i++){
		if(f1%i==0){
			int count = 0;
			while(f1%i==0){
				f1 = f1/i;
				count++;
			}
			m1[i] = count;
		}
	}
	if(f1>=2)m1[f1]=1;
	
	for(int i=2;i*i<=f2;i++){
		if(f2%i==0){
			int count = 0;
			while(f2%i==0){
				f2 = f2/i;
				count++;
			}
			m2[i] = count;
		}
	}
	if(f2>=2)m2[f2]=1;
	
	for(int i=2;i*i<=f3;i++){
		if(f3%i==0){
			int count = 0;
			while(f3%i==0){
				f3 = f3/i;
				count++;
			}
			m3[i] = count;
		}
	}
	if(f3>=2)m3[f3]=1;
	
	for(int i=2;i*i<=cc;i++){
		if(cc%i==0){
			int count = 0;
			while(cc%i==0){
				cc = cc/i;
				count++;
			}
			m4[i] = count;
		}
	}
	if(cc>=2)m4[cc]=1;
	
	ll res = 1;
	unordered_set<ll> st;
	
	for(auto it = m1.begin();it!=m1.end();it++){
		if(st.find((*it).F)==st.end()){
			ll prime = (*it).F;
			ll B[3];
			B[0] = m4[prime]*3 + m3[prime];
			B[1] = m4[prime]*2 + m2[prime];
			B[2] = m4[prime] + m1[prime];
			ll temp = 0;
			f(i,3)temp = (temp+(B[i]*P[0][i]))%mod2;
			res = (res*power(prime,temp,mod))%mod;
			st.insert(prime);
		}
	}
	
	
	for(auto it = m2.begin();it!=m2.end();it++){
		if(st.find((*it).F)==st.end()){
			ll prime = (*it).F;
			ll B[3];
			B[0] = m4[prime]*3 + m3[prime];
			B[1] = m4[prime]*2 + m2[prime];
			B[2] = m4[prime] + m1[prime];
			ll temp = 0;
			f(i,3)temp = (temp+(B[i]*P[0][i]))%mod2;
			res = (res*power(prime,temp,mod))%mod;
			st.insert(prime);
		}
	}
	
	for(auto it = m3.begin();it!=m3.end();it++){
		if(st.find((*it).F)==st.end()){
			ll prime = (*it).F;
			ll B[3];
			B[0] = m4[prime]*3LL + m3[prime];
			B[1] = m4[prime]*2LL + m2[prime];
			B[2] = m4[prime] + m1[prime];
			ll temp = 0;
			f(i,3)temp = (temp+(B[i]*P[0][i]))%mod2;
			res = (res*power(prime,temp,mod))%mod;
			st.insert(prime);
		}
	}
	
	for(auto it = m4.begin();it!=m4.end();it++){
		if(st.find((*it).F)==st.end()){
			ll prime = (*it).F;
			ll B[3];
			B[0] = m4[prime]*3LL + m3[prime];
			B[1] = m4[prime]*2LL + m2[prime];
			B[2] = m4[prime] + m1[prime];
			ll temp = 0;
			f(i,3)temp = (temp+(B[i]*P[0][i]))%mod2;
			res = (res*power(prime,temp,mod))%mod;
			st.insert(prime);
		}
	}

	res = (res*moPow(cs,n))%mod;	
	cout<<res<<"\n";
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
