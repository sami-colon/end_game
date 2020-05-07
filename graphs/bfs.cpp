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

void bfs(vector<vector<int> > &graph, int source)
{
	bool visited[graph.size()];
	for(int i=0; i<graph.size(); i++)
	{
		visited[i] = 0;
	}
	queue<int>q;
	q.push(source);
	visited[source] = true;
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		cout << curr << " ";
		for(auto x: graph[curr])
		{
			if(!visited[x])
			{
				q.push(x);
				visited[x] = 1;
			}
		}
	}
	cout << endl;
}

int main()
{
	// using adjancency list.
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
	bfs(graph, 1);
	return 0;
}