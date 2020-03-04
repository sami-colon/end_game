#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		int increasing[n], decreasing[n];
		increasing[0] = 1; decreasing[n-1] = 1;
		for(int i=1; i<n; i++){
			if(arr[i] >= arr[i-1]){
				increasing[i] = increasing[i-1] + 1;
			}
			else{
				increasing[i] = 1;
			}
			if(arr[n-i-1] >= arr[n-i]){
				decreasing[n-i-1] = decreasing[n-i] + 1;
			}
			else{
				decreasing[n-i-1] = 1;
			}
		}
		int ans = 1;
		for(int i=0; i<n; i++){
			ans = max(ans, increasing[i] + decreasing[i] - 1);
		}
		cout << ans<< endl;
	}
	return 0;
}