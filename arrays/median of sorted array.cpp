#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n+n];
	for(int i=0; i<2*n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n+n);
	cout << (arr[(int)floor(2*n + 1 - 1) / 2] + arr[(int)ceil(2*n + 1 - 1) / 2]) / 2<< endl;
	return 0;
}