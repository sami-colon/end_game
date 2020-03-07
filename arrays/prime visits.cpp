#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int x){
	if(x%2 == 0) return false;
	int c=1;
	for(int i=3; i<= sqrt(x); i+=2){
		if(x % i == 0) c++;
		if(c == 2) return false;
	}
	return true;
}

int main(){
	int *presum = new int[1000000+1];
	presum[0] = 0; presum[1] = 0; presum[2] = 1;
	for(int i=3; i<=1000000; i++){
		if(isPrime(i)){
			presum[i] = presum[i-1] + 1;
		}
		else{
			presum[i] = presum[i-1];
		}
	}
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		cout << presum[b] - presum[a-1] << endl;
	}
	return 0;
}