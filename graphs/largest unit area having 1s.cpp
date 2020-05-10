// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

#define SIZE 100


 // } Driver Code Ends


/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   g[][]: 2D matrix from input
*/
bool isSafe(int i, int j, int n, int m)
{
    return (i>=0 && j>=0 && i<n && j<m);
}


void dfs(int **g, int i, int j, int n, int m, int & curr)
{
	cout << "inside dfs\n" << i << " " << j << "\n";
    if(!(i>=0 && j>=0 && i<n && j<m))
        return;
    if(g[i][j] == 1)
    {
        curr++;
        g[i][j] = 0;
        int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
        int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
        for(int pos=0; pos<8; pos++)
        {
            int newx = i + x[pos];
            int newy = j + y[pos];
            if(isSafe(newx, newy, n, m) && g[newx][newy] == 1)
            {
                dfs(g, newx, newy, n,m, curr);
            }
        }
    }
}

int findMaxArea(int n, int m, int g[SIZE][SIZE] )
{
	int **arr = new int*[n];
	for(int i=0; i<n; i++)
	{
		arr[i] = new int(m);
		for(int j=0; j<m; j++)
		{
			arr[i][j] = g[i][j];
		}
	}
    int ans = 0, curr = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
        	cout << "inside loop\n";
            if(arr[i][j] == 1)
            {
            	cout << "inside if\n";
                curr = 0;
                dfs(arr, i, j, n,m, curr);
                ans = max(ans, curr);
            }
        }
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
}  // } Driver Code Ends