// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int shortest(vector<vector<int> > grid ,int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++) 
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++) 
            {
                cin >> grid[i][j];
            }
        }
        
        cout << shortest(grid,n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// grid : given n*n grid 
// n : size of the square grid

struct cell
{
    int x,y,dist;
    cell(int x, int y, int dist): x(x), y(y), dist(dist){}
};

bool operator<(const cell &a, const cell &b)
{
    if(a.dist == b.dist)
    {
        if(a.x == b.x)
        return a.y < b.y;
        else
        return a.x < b.x;
    }
    return a.dist < b.dist;
}


bool isSafe(int i, int j, int n) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int shortest(vector<vector<int> > grid, int n)
{
    // Your code goes here.
    int dist[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dist[i][j] = INT_MAX;
        }
    }
    
    set<cell>s;
    dist[0][0] = grid[0][0];
    s.insert(cell(0,0,0));
    while(!s.empty())
    {
        // take smallest element.
        cell curr = *s.begin();
        s.erase(s.begin());
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int x = curr.x + dx[i];
            int y = curr.y + dy[i];
            if(isSafe(x, y, n))
            {
                // apply relaxation.
                if(dist[x][y] > dist[curr.x][curr.y] + grid[x][y])
                {
                    if(dist[x][y] != INT_MAX)
                    {
                        // if its not initial marking. Then there is some previous cell. we must remove it.
                        s.erase(s.find(cell(x, y, dist[x][y])));
                    }
                    dist[x][y] = dist[curr.x][curr.y] + grid[x][y];
                    s.insert(cell(x,y,dist[x][y]));
                }
            }
        }
    }
    return dist[n-1][n-1];
}