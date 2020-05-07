#include<iostream>
#include<vector>
using namespace std;

// for undirected graph.

void addEdge(vector<vector<int> > &graph, int source, int destination)
{
	graph[source].push_back(destination);
	graph[destination].push_back(source);
}

bool dfs(std::vector<std::vector<int> > &graph, int source, bool* visited, int parent)
{
	visited[source] = true;
	for(auto x: graph[source])
	{
		if(visited[x] == true)
		{
			if(x != parent)
				return true;
		}
		else
		{
			if(dfs(graph, x, visited, source))
				return true;
		}
	}
	return false;
}

int main()
{
	int n = 5;
	vector<vector<int> > graph(n + 1);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	addEdge(graph, 4, 5);
	addEdge(graph, 5, 3);
	bool visited[n + 1] = {0};
	cout << dfs(graph, 1, visited, -1);
	return 0;
}