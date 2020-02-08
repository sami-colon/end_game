#include<iostream>
#include<vector>
#include<string>
using namespace std;

int isSafe(char ** grid, int row, int col, string str){
	int ans = 0;
	int c = 0;
	// make starting index correct by putting it back.
	for(int i=row-1; i>=0; i--){
		if(grid[i][col] != '+'){
			c++;
		}
		else{
			break;
		}
	}
	row = row - c;
	// check vertically.
	string space = "";
	for(int i=row; i<10; i++){
		space += grid[i][col];
	}
	for(int i=0; i<str.size(); i++){
		if(!(space[i] == '-' || space[i] == str[i])){
			ans = -1;
		}
	}
	if(ans == 0)
		return 1;
	// check horizontally.
	// make starting index correct by putting it back.
	c=0;
	for(int i=col-1; i>=0; i--){
		if(grid[row][i] != '+'){
			c++;
		}
		else{
			break;
		}
	}
	col = col - c;
	ans = 0;
	space = "";
	for(int i=col; i<10; i++){
		space += grid[row][i];
	}
	for(int i=0; i<str.size(); i++){
		if(!(space[i] == '-' || space[i] == str[i])){
				ans = -1;
		}
	}
	if(ans == 0)
		return 2;
	return -1;
}

bool find_empty(char ** grid, int &row, int &col){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(grid[i][j] == '-'){
				row = i; col = j;
				return true;
			}
		}
	}
	row = -1; col = -1;
	return false;
}

void solve_grid_every(char ** grid, vector<string> v){
	// base case
	// check for empty spaces.
	int row, col;
	if(!find_empty(grid, row, col)){
		// considering solution exists in every test case.
		// print
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	// for every string in vector try to solve grid.
	for(int i=0; i<v.size(); i++){
		int type = isSafe(grid, row, col, v[i]);
		// make backup string for unset.
		string backup = ""; int c=0;
		if(type != -1){
			// set
			if(type == 1){
				// insert vertically.
				// make starting index correct by putting it back.
				for(int j=row-1; j>=0; j--){
					if(grid[j][col] != '+'){
						c++;
					}
					else{
						break;
					}
				}
				row = row - c;
				for(int j=0; j<v[i].size(); j++){
					backup += grid[j+row][col];
					grid[j+row][col] = v[i][j];
				}
			}
			if(type == 2){
				// insert horizontally.
				c=0;
				for(int i=col-1; i>=0; i--){
					if(grid[row][i] != '+'){
						c++;
					}
					else{
						break;
					}
				}
				col = col - c;
				for(int j=0; j<v[i].size(); j++){
					backup += grid[row][j+col];
					grid[row][col+j] = v[i][j];
				}
			}
			// remove v[i] from vector list.
			vector<string> v1;
			for(int j=0; j<v.size(); j++){
				if(i == j)
					continue;
				else
					v1.push_back(v[j]);
			}
			// move 
			solve_grid_every(grid, v1);
			// unset
			// insert backup string in grid.	
			if(type == 1){
				// insert vertically.
				for(int j=0; j<v[i].size(); j++){
					grid[j+row][col] = backup[j];
				}
			}
			if(type == 2){
				// insert horizontally.
				for(int j=0; j<v[i].size(); j++){
					grid[row][col+j] = backup[j];
				}
			}		
		}

	}
	return;
}

int main(){
	char **grid = new char*[10];
	string str;
	for(int i=0; i<10; i++){
		grid[i] = new char[10];
		cin >> str;
		for(int j=0 ;j<10; j++){
			grid[i][j] = str[j];
		}
	}
	vector<string> v;
	cin >> str;
	int start = 0, len = 0;
	for(int i=0; i<str.size(); i++){
		if(str[i] == ';'){
			v.push_back(str.substr(start, len));
			start = i+1;
			len = 0;
		}
		else{
			len ++ ;
		}
	}
	v.push_back(str.substr(start, len));
	solve_grid_every(grid, v);
	return 0;
}