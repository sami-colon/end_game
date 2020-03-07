#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int presum[n];
	cin >> presum[0];
	for(int i=1; i<n; i++){
		cin >> presum[i];
		presum[i] = presum[i] + presum[i-1];
	}
	int k;
	cin >> k;
	int left = 0, right = 0, max = 0;
	for(int i=0; i<n-k; i++){
		if(presum[i+k] - presum[i] > max){
			max = presum[i+k] - presum[i];
			left = i; right = i+k;
		}
	}
	for(int i=left; i<=right; i++){
		if(i == 0){
			cout << presum[i] << ", ";
			continue;
		}
		cout << presum[i] - presum[i-1] << ", ";
	}
	cout << endl;
	return 0;
}