#include<iostream>
using namespace std;
int main(){
	string str;
	cin >> str;
	if(str[0] != '9' && str[0] - '0' >4)
		str[0] = (char)(9 - (int)(str[0] - '0')) + '0';
	for(int i=1; i<str.length(); i++){
		if(str[i] - '0' > 4){
			str[i] = (char)(9 - (str[i] - '0')) + '0';
		}
	}
	cout << str << endl;
	return 0;
}