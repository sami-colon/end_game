#include<bits/stdc++.h>
using namespace std;

vector<int> topological_sort(vector<vector<int > > &graph)
{
	// using kahns algorithm.
	int n = graph.size();
	int visited[n] = {0};
	int indegree[n] = {0};
	// create indegree array.
	for(int i=0; i<n; i++)
	{
		for(auto x: graph[i])
		{
			indegree[x]++;
		}
	}
	// create queue.
	queue<int> s;
	vector<int>ans;
	for(int i=0; i<n; i++)
	{
		if(indegree[i] == 0)
			s.push(i);
	}
	// starts bfs.
	while(!s.empty())
	{
		int curr = s.front(); s.pop();
		ans.push_back(curr);
		for(auto x: graph[curr])
		{
			indegree[x]--;
			if(visited[x] == 0 && indegree[x] == 0)
			{
				s.push(x);
				visited[x] = 1;
			}
		}
	}
	return ans;
}

int main()
{
	int v;
	std::vector<vector<int > > graph(v+1);
	// create graph.
	// create weight matrix or list.
	// find topological sort
	vector<int> sorted = topological_sort(graph);
	// make distances
	int distances[v+1] = {0};
	int source = 0;
	// make disatnces Infinte.
	for(int i=0; i<=v; i++)
	{
		distances[i] = INT_MAX;
		if(i == source)
			distances[i] = 0;
	}
	// for each vertex of topological sort start doing relaxation.
	for(auto x: sorted)
	{
		int u = x;
		for(auto v: graph[x])
		{
			// apply relaxation.
			if(distances[v] > distances[u] + weights[u][v])
			{
				distances[v] = distances[u] + weights[u][v]
			}
		}
	}
}