#include<iostream>
#include<vector>
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
		cout << source << " ";
		for(auto x: graph[source])
		{
			dfs(graph, x, visited);
		}
	}
	return;
}

int main()
{
	int n = 5;
	vector<vector<int> > graph(n + 1);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 4, 2);
	addEdge(graph, 2, 1);
	addEdge(graph, 2, 3);
	addEdge(graph, 1, 3);
	addEdge(graph, 3, 5);
	addEdge(graph, 4, 3);
	bool visited[n + 1] = {0};
	dfs(graph, 1, visited);
	return 0;
}