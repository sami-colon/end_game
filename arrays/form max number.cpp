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
		cout << a << " " << b << endl;
		return a < b;
	}
	else if(anum > bnum){
		int p = pow(10, anum - bnum);
		cout << a << " " << b*p << endl;
		return a <= b*p;
	}
	else{
		int p = pow(10, bnum - anum);
		cout << a*p << " " << b << endl;
		return b <= a*p;
	}
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
		// sort(arr, arr+n, comp);
		for(int i=0; i<n; i++){
			for(int j=i; j<n; j++){
				if(comp(arr[i], arr[j])){
					arr[i] = arr[i] + arr[j];
					arr[j] = arr[i] - arr[j];
					arr[i] = arr[i] - arr[j];
				}
			}
		}
		for(int i=0; i<n; i++){
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}