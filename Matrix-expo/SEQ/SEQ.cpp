#include<bits/stdc++.h>
#define pb push_back 
#define mp make_pair 
#define ll long long 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++)
 
#define N 10 
using namespace std;
 
ll mod = 1e9;
 
ll F[N][N];
ll P[N][N];
ll B[N];
 
ll k;
 
void multiply(ll a[N][N],ll b[N][N]){
	ll res[N][N];
	f(i,k){
		f(j,k){
			ll temp = 0;
			f(p,k){
				temp=(temp+(a[i][p]*b[p][j])%mod)%mod;
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
 
ll solve(ll n){
	if(n<=k)
		return B[n-1]%mod;
	power(P,n-k);
	ll res = 0;
	f(i,k)res=(res+(P[0][i]*B[i])%mod)%mod;
	return res;
}
 
void test(){
	cin>>k;
	ll b[k];
	f(i,k)cin>>b[i];
	ll c[k];
	f(i,k)cin>>c[i];
	ll n;
	cin>>n;
	f(i,N)f(j,N)F[i][j]=0;
	f(j,k)F[0][j]=c[j];
	fr(i,1,k){
		F[i][i-1]=1;
	}
	f(i,k)B[k-1-i]=b[i];
	f(i,N)f(j,N)P[i][j]=F[i][j];
	cout<<solve(n)<<"\n";
	
}
 
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		test();
	}
} 
