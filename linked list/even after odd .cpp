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



int main(){
	int n;
	cin >> n;
	node* odd = NULL, *even = NULL;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		if(x&1) odd = insertBack(odd, x);
		else even = insertBack(even, x);
	}
	node* ptr = odd;
	while(ptr!=NULL && ptr->next != NULL){
		ptr = ptr->next;
	}
	if(ptr){
		ptr->next = even;
		print(odd);
	}
	else
		print(even);
	return 0;
}