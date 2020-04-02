#include<iostream>
#include<stack>
using namespace std;

int main(){
	int prices[7] = {100, 80, 60, 70, 60, 75, 85};
	int ans[7] = {0};
	stack<int>s, aux;
	s.push(prices[0]);
	ans[0] = 0;
	for(int i=1; i<7; i++){
		int curr = prices[i];
		if(s.top() > curr){
			ans[i] = 1;
			s.push(curr);
		}
		else{
			int count = 1;
			while(!s.empty() && s.top() <= curr){
				count++;
				int x = s.top(); s.pop();
				aux.push(x);
			}
			if(s.empty()){
				ans[i] = 0;
			}
			else{
				ans[i] = count;
			}
			while(!aux.empty()){
				int x = aux.top();	aux.pop();
				s.push(x);
			}
			s.push(curr);
		}
		cout << ans[i] << " ";
	}
	return 0;
}