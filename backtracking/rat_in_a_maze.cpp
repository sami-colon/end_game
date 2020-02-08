#include<iostream>
using namespace std;

bool isSafe(int **maze, int **bk, int n, int row, int col){
	if(row>=n || col>=n || row<0 || col<0)
		return false;
	if(maze[row][col]==0 || bk[row][col]==1)
		return false;
	return true;
}

void maze_solver(int **maze, int **bk, int n, int row, int col){
	// base case.
	// if row and col = n-1, i.e we reached the end;
	if(row == n-1 && col == n-1){
		// print bk
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout << bk[i][j] << " ";
			}
		}
		cout << endl;
		return;
	}
	// we have 4 possible directions.
	// down, right, top, left.
	int possible_x[4] = {1, 0, -1, 0};
	int possible_y[4] = {0, 1, 0, -1};
	// try every possible directions.
	for(int i=0; i<4; i++){
		if(isSafe(maze, bk, n, row + possible_x[i], col + possible_y[i])){
			// set
			bk[ row + possible_x[i] ][ col + possible_y[i] ] = 1;
			// move 
			maze_solver(maze, bk, n, row + possible_x[i], col + possible_y[i]);
			// unset
			bk[ row + possible_x[i] ][ col + possible_y[i] ] = 0;
		}
	}
	return;
}

int main(){
	int n;
	cin>>n;
	int **maze = new int*[n];
	int **bk = new int*[n];
	for(int i=0;i<n;i++){
		maze[i]  =new int[n];
		bk[i]  =new int[n];
		for(int j=0;j<n;j++){
			cin >> maze[i][j];
			bk[i][j] = 0;
		}
	}
	bk[0][0] = 1;
	maze_solver(maze, bk, n, 0, 0);
}