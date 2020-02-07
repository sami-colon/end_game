#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int **bk, int row, int col){
	if(row == 0)
		return true;
	if(bk[row-1][col] == 1)
		return false;
	return true;
}

void getSum(int **arr, int **bk, int row, int n, int curr_sum, int &best_sum){
	// base case.
	// print accumulated sum.
	if(row == n){
		best_sum = min(best_sum, curr_sum);
		return;
	}
	// try every other column and move forward.
	for(int i=0; i<3; i++){
		// only if save to get these pencil.
		if(isSafe(bk, row, i)){
			// set
			curr_sum+=arr[row][i];
			bk[row][i] = 1;
			// move
			getSum(arr, bk, row+1, n, curr_sum, best_sum);
			// unset
			curr_sum-=arr[row][i];
			bk[row][i] = -1;
		}
	}
	return;

}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin >> n;
		int **arr = new int*[n], **bk = new int*[n];
		for(int i=0;i<n;i++){
			arr[i] = new int[3];
			bk[i] = new int[3];
			for(int j=0;j<3;j++){
				cin>>arr[i][j];
				bk[i][j] = -1;
			}
		}
		int best_sum = INT_MAX;
		getSum(arr, bk, 0, n, 0, best_sum);
		cout<< best_sum <<endl;
	}
	return 0;
}