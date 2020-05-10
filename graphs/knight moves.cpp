// { Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(int *, int *, int);

// Driver code to test above methods
int main()
{
	// size of square board
	int t;
	cin>>t;
	while(t--)
	{
	    int N;
	    int a,b,c,d;
	    cin>>N;
	    cin>>a>>b;
	    cin>>c>>d;
	    int knightPos[] = {a, b};
	    int targetPos[] = {c, d};
	    cout << minStepToReachTarget(knightPos, targetPos, N)<<endl;
	}
	return 0;
}
 // } Driver Code Ends


//User function template for C++

// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
bool isSafe(int i, int j, int n)
{
	return i>=0 && j>=0 && i<n && j<n;
}
int minStepToReachTarget(int knightPos[], int targetPos[],int N) {
    //code here
    // using bfs for getting shortest path.
    N++;
    bool visited[N][N];
    int distance[N][N];
    for(int a=0; a<N;a++)
    for(int b=0; b<N;b++)
    {
        visited[a][b] = false;
        distance[a][b] = INT_MAX;
    }
    queue<pair<int, int> >q;
    int i = knightPos[0];
    int j = knightPos[1];
    q.push(make_pair(i, j));
    visited[i][j] = true;
    distance[i][j] = 0;
    while(!q.empty())
    {
    	pair<int, int> curr = q.front(); q.pop();
    	i = curr.first;
    	j = curr.second;
    	if(i == targetPos[0] && j == targetPos[1])
    	{
    		return distance[i][j];
        }
    	int x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    	int y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    	for(int z=0; z<8; z++)
    	{
    		int newx = i + x[z];
    		int newy = j + y[z];
    		if(isSafe(newx, newy, N) && visited[newx][newy] == false)
    		{
    			q.push(make_pair(newx, newy));
    			visited[newx][newy] = true;
    			distance[newx][newy] = distance[i][j] + 1;
    		}
    	}
    }
    return distance[targetPos[0]][targetPos[1]];
}