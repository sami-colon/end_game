#include<iostream>
#include<stack>
using namespace std;

void usingTwoStacks(stack<int> & s){
	stack<int>s1, s2;
	// move to s1 then to s2 then to s itself.
	while(!s.empty()){
		int x = s.top();
		s.pop();
		s1.push(x);
	}
	while(!s1.empty()){
		int x = s1.top();
		s1.pop();
		s2.push(x);
	}
	while(!s2.empty()){
		int x = s2.top();
		s2.pop();
		s.push(x);
	}
	return;
}

void usingOneStack(stack<int> &s){
	stack<int> s1;
	// get size.
	int n = 0;
	while(!s.empty()){
		n++;
		int x = s.top();
		s.pop();
		s1.push(x);
	}
	while(!s1.empty()){
		int x = s1.top();
		s1.pop();
		s.push(x);
	}
	for(int i=1; i<=n; i++){
		int key = s.top();
		s.pop();
		for(int j=1; j<=n-i; j++){
			int x = s.top(); s.pop();
			s1.push(x);
		}
		s.push(key);
		while(!s1.empty()){
			int x = s1.top(); s1.pop();
			s.push(x);
		}
	}
	return;
}

void insertAtBottom(stack<int> &s, int key){
	if(s.empty()){
		s.push(key);
	}
	else{
		int x = s.top(); s.pop();
		insertAtBottom(s, key);
		s.push(x);
		return;
	}
}

void usingRecursion(stack<int> &s){
	if(s.empty()){
		return;
	}
	int key = s.top(); s.pop();
	usingRecursion(s);
	insertAtBottom(s, key);
	return;
}

int main(){
	stack<int>s;
	for(int i=1; i<=4; i++){
		s.push(i);
	}
	usingRecursion(s);
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}