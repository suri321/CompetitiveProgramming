#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	// array stores the basic tiling, repetiton maybe there, i.e. the cases which are read same from beginning and end are included.
	ll arr[31];
	arr[0]=0;
	arr[1]=1;
	arr[2]=3;
	for(int i=3;i<=30;i++){
		arr[i]=arr[i-1]+(2*arr[i-2]);
	}
	// actual answers are stored in it, the special cases of reading same from beginning and ending are removed.
	ll table[31];
	table[0]=0;
	table[1]=1;
	table[2]=3;
	table[3]=3;
	table[4]=8;
	for(int i=5;i<=30;i++){
		// the logic 
		// we have a...a,a....b,a...c,b...b,b...c,c....c cases, where a denotes 1, b denotes 2 and c denotes the horizontal 2 tiles 
		// where start and end are same, we need to insert values from "table" else from "arr".
		ll ans=table[i-2]+arr[i-3]+arr[i-3]+table[i-4]+arr[i-4]+table[i-4];
		table[i]=ans;
	}
	while(t-->0){
		int n;
		cin>>n;
		cout<<table[n]<<"\n";
	}
}
