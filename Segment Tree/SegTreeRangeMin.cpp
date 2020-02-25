#include<bits/stdc++.h>
#define pb push_back 
#define mp make_pair 
#define ll long long 
#define F first 
#define S second 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 

using namespace std;

void build_segment_tree(ll arr[],ll mintree[],ll n)
{
    for(int i=0;i<n;i++)
    {
        mintree[n+i]=arr[i];
    }
    
    for(int i=n-1; i>0 ;i--)
    {
        // for range min Quereies
        mintree[i]=min(mintree[2*i],mintree[(2*i)+1]);
    }
}

// update arr[index]=value, and make changes accordingly to the segment tree
void update_segment_tree(int index,ll value,ll n,ll mintree[])
{
    mintree[index+n]=value;
    index=index+n;
    
    for(int i=index;i>=1;i=i/2)
    {
        // for range min Quereies
        mintree[i/2]=min(mintree[i],mintree[i^1]);
    }
}

// query for interval [l,r)
ll query(int l,int r,ll n,ll mintree[])
{
    ll min_res=INT_MAX;
    for(l=l+n,r=r+n;l<r;l=l/2,r=r/2)
    {
        if(l%2==1)
        {
            min_res=min(min_res,mintree[l++]);
        }
        if(r%2==1)
        {
            min_res=min(min_res,mintree[--r]);
        }
    }
    return min_res;
}

int main()
{
	ll n;
	cin>>n;
    ll arr[n];
    f(i,n)cin>>arr[i];
	ll mintree[2*n];
	build_segment_tree(arr,mintree,n);
	
	int que;
	cin>>que;
	while(que--){
		int qtype;
		cin>>qtype;
		
		if(qtype==1){ // query type 1 update a[i] = b;  // 0-based indexing 
			ll index,val;
			cin>>index>>val;
			update_segment_tree(index,val,n,mintree); 
		}else{ // query type 2 : print minimum of  a[l] , a[l+1] , .. , a[r] // 0-based indexing 
			int left,right;
			cin>>left>>right;  
			ll c=query(left,right+1,n,mintree);
			cout<<c<<"\n";
		}
	}
}


