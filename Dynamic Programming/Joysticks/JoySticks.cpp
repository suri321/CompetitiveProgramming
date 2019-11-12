#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int count=0;
	if(n<m)swap(n,m);
	while(n>1 and m>=1){
		count++;
		m++;
		n=n-2;
		if(n<m)swap(n,m);
	}
	cout<<count<<"\n";
}
