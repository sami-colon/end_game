#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// for undirected graph.

void addEdge(vector<vector<int> > &graph, int source, int destination)
{
	graph[source].push_back(destination);
	graph[destination].push_back(source);
}

void dfs(std::vector<std::vector<int> > &graph, int source, bool* visited)
{
	if(!visited[source])
	{
		visited[source] = 1;
		// cout << source << " ";
		for(auto x: graph[source])
		{
			dfs(graph, x, visited);
		}
	}
	return;
}

int main()
{
	// using adjancency list.
	int n = 5;
	vector<vector<int> > graph(n + 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 4, 3);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 3);
	int c = 0;
	bool visited[n+1] = {0};
	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
		{
			c++;
			dfs(graph, i, visited);
		}
	}
	cout << c << endl;
	return 0;
}