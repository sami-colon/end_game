#include<iostream>
using namespace std;

#define N 9

bool isSafe(int ** grid, int row, int col, int val){
	// check vertically and horizontally.
	for(int i=0; i<9; i++){
		if(grid[i][col] == val || grid[row][i] == val){
			return false;
		}
	}
	// check inside inner grid.
	int start_i1, start_j1;
	start_i1 = row - (row % 3);
	start_j1 = col - (col % 3);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(grid[ i + start_i1 ][ j + start_j1 ] == val)
				return false;
		}
	}
	return true;
}

bool vacant_space(int **grid, int &row, int &col){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(grid[i][j] == 0){
				row = i;col = j;
				return true;
			}
		}
	}
	row = -1; col = -1;
	return false;
}

bool sudoku_solver_first(int ** grid){
	// base case. No vacant space = return true.
	// find next vacant space.
	int row, col;
	// if not found vacant. sudoku alreday solved.
	if(!vacant_space(grid, row, col)){
		return true;
	}
	// for every value from 1 -> 9 try to solve sudoku at this row and col.
	for(int i=1; i<=9; i++){
		if(isSafe(grid, row, col, i)){
			// set 
			grid[row][col] = i;
			// move 
			if(sudoku_solver_first(grid)){
				// if true then return 
				return true;
			}
			// else unset and try again.
			grid[row][col] = 0;
		}
	}
	// no answer found.
	return false;
}

void sudoku_solver_every(int **grid){
	// base case. No vacant space = return true.
	// find next vacant space.
	int row, col;
	// if not found vacant. sudoku alreday solved.
	if(!vacant_space(grid, row, col)){
		// print sudoku.
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	// for every value from 1 -> 9 try to solve sudoku at this row and col.
	for(int i=1; i<=9; i++){
		if(isSafe(grid, row, col, i)){
			// set 
			grid[row][col] = i;
			// move 
			sudoku_solver_every(grid);
			// unset
			grid[row][col] = 0;
		}
	}
	return;
}

int main(){
	int **grid = new int*[N];
	for(int i=0; i<N; i++){
		grid[i] = new int[N];
		for(int j=0; j<N; j++){
			cin >> grid[i][j];
		}
	}
	sudoku_solver_every(grid);
	return 0;
}