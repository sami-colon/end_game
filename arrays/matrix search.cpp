#include<iostream>
using namespace std;

bool find(int** arr, int x, int n, int m){
	int row=0, col=m-1;
	while(row>=0 && row<n && col>=0 && col<m){
		if(arr[row][col] == x) return 1;
		else if(arr[row][col] > x) col = col-1;
		else row=row+1;
	}
	return 0;
}

int main(){
	int n,m;
	cin >> n >> m;
	int **arr = new int*[n];
	for(int i=0; i<n; i++){
		arr[i] = new int[m];
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	int x; cin >> x;
	cout << find(arr, x, n, m) << endl;
	return 0;
}