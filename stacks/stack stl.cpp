#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> s;
	s.push(10); // insertion.
	s.pop();	// deletion.
	s.top();	// peeking the top element.
	s.empty();	// return empty or not.
	return 0;
}