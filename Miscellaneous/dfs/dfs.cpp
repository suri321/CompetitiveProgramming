
int count1[N]; 
vector<int> adj[N]; 
 
void numberOfNodes(int s, int e) 
{ 
    count1[s] = 1; 
    for(int i=0;i<adj[s].size();i++){
    	if(adj[s][i]==e)continue;
    	numberOfNodes(adj[s][i],s);
    	count1[s]+=count1[adj[s][i]];
	}
} 

numberOfNodes(1, 0);


