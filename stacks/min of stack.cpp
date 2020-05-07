#include<iostream>
#include<vector>
using namespace std;

class Stack{
private:
	std::vector<int> v;
	int min;
public:
	void push(int x){
		if(v.size() == 0){
			min = x;
			v.push_back(x);
		}
		else{
			if(x >= min){
				v.push_back(x);
			}
			else{
				v.push_back(2*x - min);
				min = x;
			}
		}
	}
	void pop(){
		if(v.size() == 0){
			return;
		}
		if(v[v.size()-1] >= min){
			v.pop_back();
		}
		else{
			min = 2*min - v[v.size()-1];
			v.pop_back();
		}
	}
	int top(){
		if(v.size() == 0){
			return -404;
		}
		if(v[v.size()-1] < min){
			return min;
		}
		else{
			return v[v.size()-1];
		}
	}
	int getMin(){
		if(v.size() == 0){
			return -404;
		}
		return min;
	}
}

int main(){
	Stack s;
	int n;
	cin >> n;
	while(n--){
		int x; cin >> x;
		s.push(x);
	}
	return 0;
}