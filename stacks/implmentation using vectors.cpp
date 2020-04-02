#include<iostream>
#include<vector>
using namespace std;

class Stack{
private:
	vector<int>v;
public:
	bool isEmpty(){
		return v.size() == 0;
	}
	void push(int x){
		v.push_back(x);
	}
	void pop(){
		if(!isEmpty())
			v.pop_back();
	}
	int top(){
		if(!isEmpty()){
			return v[v.size() - 1];
		}
		else{
			cerr << "Empty Nothing to Show" << endl;
			return -404;
		}
	}
};

int main(){
	Stack s1;
	cout << s1.top();
	return 0;
}