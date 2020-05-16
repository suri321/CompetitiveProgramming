
int count1[N]; 
vector<int> adj[N]; 
 
void numberOfNodes(int s, int e) 
{ 
    vector<int>::iterator u; 
    count1[s] = 1; 
    for (u = adj[s].begin(); u != adj[s].end(); u++) { 
        if (*u == e) 
            continue; 
        numberOfNodes(*u, s); 
        count1[s] += count1[*u]; 
    } 
} 

numberOfNodes(1, 0);


