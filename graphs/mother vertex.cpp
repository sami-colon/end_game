#include <bits/stdc++.h> 
using namespace std; 

/*
 * Function to find if there is a mother vertex in the given graph 
 * V: number of vertices in the graph
 * adj[]: graph representation
 */


void dfs(bool* visited, int curr, vector<int> *adj)
{
    if(!visited[curr])
    {
        visited[curr] = true;
        for(auto x: adj[curr])
        {
            if(!visited[x])
            {
                dfs(visited, x, adj);
            }
        }
    }
    return;
}

bool isAllVisited(bool* visited, int n)
{
    for(int i=0; i<n; i++)
    {
        if(visited[i] == false)
        return false;
    }
    return true;
}

// naive approach.

/* int findMother(int V, vector<int> adj[]) 
{ 
    // Your code here
    for(int i=0; i<V; i++)
    {
        bool visited[V];
        memset(visited, false, sizeof(visited));
        dfs(visited, i, adj);
        if(isAllVisited(visited, V))
            return i;
    }
    return -1;
} 
*/

// optimised approach based on kosaraju scc approach.
// if there exists any mother vertex it will be the last one to be completeed in dfs.
// find last completed vertex . apply dfs to  check if its mother vertex.
int findMother(int V, vector<int> adj[]) 
{ 
	stack<int>s;
	bool visited[V];
	memset(visited, false, sizeof(visited));
	int motherVertex = 0;
	for (int i = 0; i < V; ++i)
	{
		if(!visited[i])
		{
			dfs(visited, i, adj);
			motherVertex = i;
		}
	}
	memset(visited, false, sizeof(visited));
    dfs(visited, motherVertex, adj);
    if(isAllVisited(visited, V))
        return motherVertex;
    return -1;
} 


int main() 
{ 
    int T;
    cin>>T;
    while(T--){
        int num, edges;
        cin>>num>>edges;
        
        vector<int> adj[num];
        
        int u, v;
        while(edges--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        cout<<findMother(num, adj)<<endl;
    }

	return 0;
}