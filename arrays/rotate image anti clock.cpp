#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	// print ans directly.
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<n; j++){
			cout << arr[j][i] << " ";
		}
		cout << endl;
	}
	// store in other array.
	int ans[n][n];
	int row=0, col=0;
	for(int i=n-1; i>=0; i--){
		col = 0;
		for(int j=0; j<n; j++){
			 ans[row][col++] = arr[j][i];
		}
		row++;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}