#include<bits/stdc++.h>
using namespace std;

void addEdge(vector< vector<int>> &graph, int source, int dest)
{
	graph[source].push_back(dest);
}

void topological_sort(vector<vector<int> >&graph, int * indegree, int n)
{
	bool * visited = new bool[n + 1]{false};
	queue<int> data;
	for(int i=0; i<graph.size(); i++)
	{
		if(indegree[i] == 0 && visited[i] == false)
		{
			data.push(i);
			visited[i] = true;
		}
	}
	while(!data.empty())
	{
		int curr = data.front();
		data.pop();
		cout << curr << endl;
		for(auto x: graph[curr])
		{
			indegree[x]--;
			if(indegree[x] == 0 && visited[x] == false)
			{
				data.push(x);
				visited[x] = true;
			}
		}
	}
}

int main()
{
	int n = 5;
	vector<vector<int> >graph(n+1);
	int * indegree = new int[ n + 1]{0};
	addEdge(graph, 0, 1);
	indegree[1]++;
	addEdge(graph, 0, 2);
	indegree[2]++;
	addEdge(graph, 2, 3);
	indegree[3]++;
	addEdge(graph, 2, 4);
	indegree[4]++;
	addEdge(graph, 4, 5);
	indegree[5]++;
	addEdge(graph, 1, 3);
	indegree[3]++;
	topological_sort(graph, indegree, n);
	return 0;
}