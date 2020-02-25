#include<iostream>
using namespace std;

bool staircase_search(int arr[4][4], int key, int &row, int &col){
	// O (n) approach.
	row = -1; col = -1;
	// start from top right so that we can get upper bound.
	int i=0, j=3;
	while(i<4 && i>-1 && j<4 && j>-1){
		if(arr[i][j] == key){
			row = i; col = j;
			return true;
		}
		else if(arr[i][j] > key){
			// move left.
			j-=1;
		}
		else{
			i+=1;
		}
	}
	return false;
}

bool binary_search_plus_linear_search(int arr[4][4], int key, int &row, int &col){
	// O(n X log(n) ) approach.
	row = -1; col = -1;
	bool result = false;
	for(int i=0; i<4; i++){
		// use binary search from j=0 to j=4-1
		int start = 0, end = 3;
		while(start <= end){
			int mid = (start + end) / 2;
			if(arr[i][mid] == key){
				row = i; col = mid;
				return true;
			}
			else if(arr[i][mid] > key){
				end = mid-1;
			}
			else{
				start = mid + 1;
			}
		}
	}
	return false;
}

bool naive(int arr[4][4], int key, int &row, int &col){
	// naive O(n X n) approach.
	row = -1; col = -1;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(arr[i][j] == key){
				row = i; col = j;
				return true;
			}
		}
	}
	return false;
}

int main(){
	// input will be sorted in both rows and columns.
	int arr[4][4];
	// take input.
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin >> arr[i][j];
		}
	}
	// take key input.
	int key;
	cin >> key;
	return 0;
}