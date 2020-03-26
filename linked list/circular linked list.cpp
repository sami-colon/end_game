#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int x): data(x){
		next = NULL;
	}
	void set(int x){
		data = x;
	}
};

node*  insertHead(int x, node* head=NULL){
	node* temp = new node(x);
	if(head == NULL){
		// first element to insert.
		temp->next = temp;
	}
	else{
		temp->next = head;
		node* slow = head;
		while(slow->next != head){
			slow=slow->next;
		}
		slow->next = temp;
	}
	return temp;
}

void print(node* head){
	node* slow = head;
	while(slow->next != head){
		cout << slow->data << " -> ";
		slow = slow->next;
	}
	cout << slow->data << endl;;
}

void takeInput(node * &head){
	int x;
	cin >> x;
	while(x!=-1){
		head = insertHead(x, head);
		cin >> x;
	}
	return;
}

node* getNode(int x, node* head){
	if(head == NULL) return NULL;
	node* slow = head;
	while(slow->next != head){
		if(slow->data == x) return slow;
		slow= slow->next;
	}
	if(slow->data == x) return slow;
	return NULL;
}


node* deleteNode(int x, node* head){
	node* del = getNode(x, head);
	if(del == NULL) return head;
	if(head->next == head && head->data == x){
		delete head;
		return NULL;
	}
	node* slow = head;
	while(slow->next != del){
		slow = slow->next;
	}
	if(del == head)
		head = slow->next->next;
	slow->next = slow->next->next;
	delete del;
	return head;
}

istream& operator>>(istream& is, node* &head){
	takeInput(head);
	return is;
}

ostream& operator<<(ostream& os, node* head){
	if(head)
		print(head);
	return os;
}

int main(){
	// create a circular linked list.
	node* head = NULL;
	// takeInput(head);
	cin >> head;
	// print(head);
	cout << head; 
	return 0;
}