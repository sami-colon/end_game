#include<iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	for(int i=0; i<str.length(); i++){
		char ch = str[i];
		int c=1;
		for(int j=i+1; j<str.length(); j++){
			if(str[j] == ch)
				c++;
		}
		cout << ch << c;
		i = i + c - 1;
	}
	return 0;
}