// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
struct cell
{
    int x, dist;
    cell(int x, int dist): x(x),dist(dist){}
};
bool operator<(const cell &a, const cell &b)
{
    if(a.dist == b.dist)
    {
        return a.x < b.x;
    }
    return a.dist < b.dist;
}
void dijkstra(vector<vector<int>> graph, int src, int n)
{
    // Your code here
    int dist[n];
    for(int i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    set<cell>st;
    st.insert(cell(src, 0));
    while(!st.empty())
    {
        cell curr = *st.begin();
        st.erase(st.begin());
        for(int i=0; i<n; i++)
        {
            if(graph[curr.x][i] != 0)
            {
                // valid vertex. Do realaxation.
                if(dist[i] > dist[curr.x] + graph[curr.x][i])
                {
                    // check and remove repating vertexs from set.
                    if(dist[i] != INT_MAX)
                    {
                        st.erase(st.find(cell(i, dist[i])));
                    }
                    dist[i] = dist[curr.x] + graph[curr.x][i];
                    st.insert(cell(i, dist[i]));
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(dist[i] == INT_MAX)
            cout << 0 << " ";
        else
        cout << dist[i] << " ";
    }
}