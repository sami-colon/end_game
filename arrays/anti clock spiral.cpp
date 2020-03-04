#include<iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> arr[i][j];
	int top, bottom, left, right;
	top = 0; bottom = n-1; left = 0; right = m-1;
	while(top<=bottom && left<=right){
		// print leftmost column.
		for(int i=top; i<=bottom; i++){
			cout << arr[i][left] << ", ";
		}
		left++;
		// print bottom row.
		for(int i=left; i<=right; i++){
			cout << arr[bottom][i] << ", ";
		}
		bottom--;
		// print right most column bottom to up.
		for(int i=bottom; i>=top; i--){
			cout << arr[i][right] << ", ";
		}
		right--;
		// print top row right to left.
		for(int i=right; i>=left; i--){
			cout << arr[top][i] << ", ";
		}
		top++;
	}
	cout << "END" << endl;
}