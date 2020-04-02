#include<iostream>
#include<vector>
using namespace std;

template<typename T, typename U>	// can define any templates or generics. Here T and U are generics.

class Stack{
private:
	vector<T> v; 	// usage of generic T
	vector<U> v2;	// usage of generic U
public:
	void push(T x){
		v.push_back(x);
	}
	void pop(){
		v.pop_back();
	}
	T top(){
		if(v.size() > 0){
			return v[v.size()-1];
		}
		else{
			return -404;
		}
	}
};