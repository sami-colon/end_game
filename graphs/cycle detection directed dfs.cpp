#include<bits/stdc++.h>
using namespace std;

void addEdge(vector< vector< int> > &graph, int source, int dest)
{
	graph[source].push_back(dest);
}
// using back edge detection for cycle detection.
// bcak edge is any edge from curr node to it ancenstor.
bool dfs(vector<vector<int> > &graph, bool* visited, bool* ancenstors, int source)
{
	visited[source] = true;
	ancenstors[source] = true;
	for(auto x: graph[source])
	{
		if(ancenstors[x] == true)
			return true;
		if(visited[x] == false && dfs(graph, visited, ancenstors, x))
			return true;
	}
	ancenstors[source] = false;
	return false;
}
int main()
{
	int n = 5;
	vector<vector<int> > graph(n+1);
	addEdge(graph, 0, 1);
	addEdge(graph, 2, 1);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 3);

	bool* ancenstors = new bool[n+1]{false};
	bool* visited = new bool[n+1]{false};
	int ans = false;
	for(int i=0; i<=5; i++)
	{
		if(!visited[i])
			ans = dfs(graph, visited, ancenstors, i);
		if(ans)
			break;
	}

	ans==true?cout << "Cycle is present" : cout << "Cycle not present";
	return 0;
}