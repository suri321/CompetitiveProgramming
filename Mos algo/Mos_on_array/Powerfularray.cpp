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

struct node {
	int L, R, i;
}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}


// modify answer and cnt in add and remove 

void add(int position) {
	cnt[a[position]]++;
	answer = answer - (cnt[a[position]]-1)*(cnt[a[position]]-1)*a[position];
	answer = answer + cnt[a[position]]*cnt[a[position]]*a[position];
}

void remove(int position) {
	cnt[a[position]]--;
	answer = answer - (cnt[a[position]]+1)*(cnt[a[position]]+1)*a[position];
	answer = answer + cnt[a[position]]*cnt[a[position]]*a[position];
}

int main() {
//	std::ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	int n,query;
	scanf("%d%d", &n, &query);
	f(i,n)cin>>a[i];
	
	for(int i=0; i<query; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].i = i;
	}

	sort(q, q + query, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<query; i++) {
		int L = q[i].L, R = q[i].R;
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i] = answer;
	}

	f(i,query)cout<<ans[i]<<"\n";
}
