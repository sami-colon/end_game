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

int kfromLast(node* head, int k){
	if(head == NULL) return -1;
	node* fast = head;
	for(int i=1; i<=k; i++){
		fast = fast->next;
	}
	node* slow = head;
	while(fast!=NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}

int main(){
	node* head = NULL;
	int x;
	cin >> x;
	while(x!=-1){
		head = insertBack(head, x);
		cin >> x;
	}
	int k;
	cin >> k;
	cout << kfromLast(head, k) << endl;
	return 0;
}