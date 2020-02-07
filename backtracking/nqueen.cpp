#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

bool isValid(int **arr, int row, int col, int n){
	// check top.
	for(int i=row-1; i>=0; i--){
		if(arr[i][col] == 1){
			return false;
		}
	}
	// check upper left and right diagonal.
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if( (i+j == row+col || (row-col) == (i-j)) && (arr[i][j] == 1)){
				return false;
			}
		}
	}
	return true;
}

void nqueen(int **arr, int row, int n){
	// base case.
	// if found soultion. print.
	if(row == n){
		// print.
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				// cout << setfill(' ') << setw(2)<< arr[i][j] << " ";
				if(arr[i][j] == 1)
					cout << 'Q' << " ";
				else
					cout << '-' << " ";
			}
			cout << endl;
		}
		cout<<endl<<endl;
		return;
	}
	// for current row start with first col and move forward for every cols.
	for(int i=0; i<n; i++){
		// check for safety of insertion.
		if(isValid(arr, row, i, n)){
			// set
			arr[row][i] = 1;
			// move forward
			nqueen(arr, row+1, n);
			// unset
			arr[row][i] = -1;
		}
	}
	return;
}

int main(){
	int n=4;
	int **arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int[n];
		for(int j=0; j<n; j++){
			arr[i][j] = -1;
		}
	}
	nqueen(arr, 0, n);
	return 0;
}