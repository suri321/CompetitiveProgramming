#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define pb push_back 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 

using namespace std;

int find(int arr[],int i){
	if(arr[i]!=i)
		arr[i]=find(arr,arr[i]);
	return arr[i];
}

void unionn(int a,int b,int arr[]){
	int pa=find(arr,a);
	int pb=find(arr,b);
	arr[pa]=pb;
	return ;
}

void test(){
	int n;
	cin>>n;
	vector<pair<int,int> > a;
	f(i,n){
		int u,v;
		cin>>u>>v;
		a.pb(mp(u,v));
	}
	int arr[n];
	for(int i=0;i<n;i++)arr[i]=i;
	f(i,n){
		fr(j,i+1,n){
			if(a[i].F==a[j].F or a[i].S==a[j].S){
				unionn(i,j,arr);
			}
		}
	}
	
	set<int> st;
	
	for(int i=0;i<n;i++)st.insert(find(arr, i));
	int ans=st.size();
	ans--;
	cout<<ans<<"\n";
	
}

int main(){
	int t=1;
//	cin>>t;
	while(t--){
		test();
	}
}
