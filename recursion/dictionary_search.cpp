#include<bits/stdc++.h>
using namespace std;

void f(string str, vector<string> &v, string ans){
	// base case.
	if(str == " " || str[0] == '\0'){
		cout << ans+")";
		return;
	}
	else{
		for(int i=0; i<str.size(); i++){
			string curr = str.substr(0, i+1);
			for(int j=0; j<v.size(); j++){
				if(v[j] == curr){
					// set 
					string ans1 = ans + curr + " ";
					// move 
					f(str.substr(i+1), v, ans1);
					// unset
					ans1 = "";
				}
			}
		}
	}
	return;
}

int main(){
	string str;
	cin >> str;
	int n;
	cin >> n;
	vector<string> v;
	for(int i=0; i<n; i++){
		string str1;
		cin >> str1;
		v.push_back(str1);
	}
	f(str, v, "(");
	return 0;
}