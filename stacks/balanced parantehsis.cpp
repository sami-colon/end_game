#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string exp){
	stack<char> s;
	for(int i=0; i<exp.size(); i++){
		if(exp[i] == '('){
			s.push('(');
		}
		else if(exp[i] == ')'){
			if(s.empty() || s.top(')'))
				return false;
			else
				s.pop();
		}
	}
	return s.empty();
}

int main(){
	string expr;
	cin >> expr;
	cout << isvalid(expr) << endl;
	return 0;
}