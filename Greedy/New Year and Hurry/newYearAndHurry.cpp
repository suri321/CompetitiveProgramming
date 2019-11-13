#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,t;
	cin>>n>>t;
	t=240-t;
	int req=5;
	int count=0;
	while(count<n and req<=t){
		count++;
		t=t-req;
		req+=5;
	}
	cout<<count<<"\n";
}
