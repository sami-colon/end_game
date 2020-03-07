#include<iostream>
using namespace std;

int find(int * mata, int n, int *matb, int m, int *ans){
	int s = 0, carry = 0;
	int x = n-1, y = m-1;
	while(x>=0 && y>=0){
		int sum = mata[x] + matb[y] + carry;
		carry = sum / 10;
		ans[s++] = sum % 10;
		x--; y--;
	}
	while(x>=0){
		int sum = mata[x] + carry;
		carry = sum / 10;
		ans[s++] = sum % 10;
		x--;
	}
	while(y>=0){
		int sum = matb[y] + carry;
		carry = sum / 10;
		ans[s++] = sum % 10;
		y--;
	}
	while(carry > 0){
		ans[s++] = carry % 10;
		carry = carry / 10;
	}
	return s;
}

int main(){
	int n;
	cin >> n;
	int mata[n];
	for(int i=0; i<n; i++){
		cin >> mata[i];
	}
	int m;
	cin >> m;
	int matb[m];
	for(int i=0; i<m; i++){
		cin >> matb[i];
	}
	int *ans = new int[100000];
	ans[0] = 0;
	int s = find(mata, n, matb, m, ans);
	for(int i=s-1; i>=0; i--){
		cout << ans[i] << ", ";
	}
	cout << "END" << endl;
}