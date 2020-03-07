#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int getDigits(int x){
	int c = 0;
	while(x){
		c++;
		x = x / 10;
	}
	return c;
}

bool comp(int a, int b){
	// get no of digits, same, uneuaqal case
	int anum = getDigits(a);
	int bnum = getDigits(b);
	if(anum == bnum){
		return a >= b;
	}
	// if a+b is greater or b+a is greater.
	return a*pow(10,bnum)+b >=  b*pow(10,anum)+a;
}

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
		sort(arr, arr+n, comp);
		for(int i=0; i<n; i++){
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}