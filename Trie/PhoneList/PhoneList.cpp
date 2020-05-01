#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define pb push_back 
#define f(i,n) for(int i=0;i<n;i++) 
#define fr(i,a,b) for(int i=a;i<b;i++) 
#define F first 
#define S second 
 
using namespace std;
 
const int size = 26;
 
struct TrieNode{
	struct TrieNode* sons[size];
	bool isEndOfWord;
};
 
struct TrieNode *getNode(void){
	struct TrieNode *pNode = new TrieNode ;
	
	for(int i=0;i<size;i++)
		pNode->sons[i] = NULL;
	pNode->isEndOfWord = false;
	return pNode;
}
 
void insert(struct TrieNode *root,string key){
	struct TrieNode* p = root;
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';
		if(!p->sons[index])
			p->sons[index]=getNode();
		p = p->sons[index];
	}
	p->isEndOfWord = true;
}
 
bool search(struct TrieNode *root,string key){
	struct TrieNode* p = root;
	for(int i=0;i<key.length();i++){
		int index = key[i]-'a';
		if(p->sons[index]){
			p = p->sons[index];
			if(p->isEndOfWord)return true;
		}else{
			return false;
		}
	}
	return true;
}
 
void test(){
	int n;
	cin>>n;
	string a[n];
	f(i,n)cin>>a[i];
	
	struct TrieNode *root = getNode();
	insert(root,a[0]);
	
	bool flag = true;
	for(int i=1;i<n;i++){
		if(search(root,a[i])){
			flag = false;
			break;
		}else
			insert(root,a[i]);
	}
	
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
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
