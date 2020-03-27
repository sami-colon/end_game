#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int x){
		data = x;
		next = NULL;
	}
};

node* insertBack(node* head, int x){
	node* temp = new node(x);
	if(head == NULL) return temp;
	node* ptr = head;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	return head;
}

void print(node* head){
	if(head){
		while(head!=NULL){
			cout << head->data << " ";
			head = head->next;
		}
	}
	return;
}

node* merge(node* a, node* b){
	if(a == NULL) return b;
	if(b == NULL) return a;
	// get samller element of both a and b. and call for subproblems.
	node* ans = NULL;
	if(a->data <= b->data){
		ans = merge(a->next, b);
		a->next = ans;
		return a;
	}
	else{
		ans = merge(a, b->next);
		b->next = ans;
		return b;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n1, n2;
		node* a= NULL, *b = NULL;
		cin >> n1;
		for(int i=0; i<n1; i++){
			int x;
			cin >> x;
			a = insertBack(a, x);
		}
		cin >> n2;
		for(int i=0; i<n2; i++){
			int x;
			cin >> x;
			b = insertBack(b, x);
		}
		a = merge(a, b);
		print(a);
	}
	return 0;
}