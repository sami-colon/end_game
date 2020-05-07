// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr, int row, int col) {

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;
}

void nearest(vector<vector<int>> arr, int row, int col) {
    vector<vector<int>> sol(row);

    for (int i = 0; i < row; i++) {
        vector<int> temp(col);
        sol[i] = temp;
    }

    int visited[row][col];
    queue<pair<int, int>> que;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = 0;
            sol[i][j] = INT_MAX;
            if (arr[i][j]) {
                visited[i][j] = 1;
                sol[i][j] = 0;
                // insert all cells that contains 1 into the queue
                que.push(make_pair(i, j));
            }
        }
    }
    // use bfs
    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();
        int x = p.first;
        int y = p.second;
        // check for the adjacent cells
        if ((x > 0) && (!visited[x - 1][y])) {
            sol[x - 1][y] = min(sol[x - 1][y], sol[x][y] + 1);
            visited[x - 1][y] = 1;
            que.push(make_pair(x - 1, y));
        }
        if ((x < (row - 1)) && (!visited[x + 1][y])) {
            sol[x + 1][y] = min(sol[x + 1][y], sol[x][y] + 1);
            visited[x - 1][y] = 1;
            que.push(make_pair(x + 1, y));
        }
        if ((y > 0) && (!visited[x][y - 1])) {
            sol[x][y - 1] = min(sol[x][y - 1], sol[x][y] + 1);
            visited[x][y - 1] = 1;
            que.push(make_pair(x, y - 1));
        }
        if ((y < (col - 1)) && (!visited[x][y + 1])) {
            sol[x][y + 1] = min(sol[x][y + 1], sol[x][y] + 1);
            visited[x][y + 1] = 1;
            que.push(make_pair(x, y + 1));
        }
    }

    print(sol, row, col);
}



// { Driver Code Starts.

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int row, col;
        cin >> row >> col;

        // Input matrix is represented using vectors of vectors
        vector<vector<int>> graph(row);

        for (int i = 0; i < row; i++) {
            vector<int> temp(col);
            graph[i] = temp;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> graph[i][j];
            }
        }

        nearest(graph, row, col);
    }

    return 0;
}  // } Driver Code Ends