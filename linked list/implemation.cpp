#include<iostream>
using namespace std;

class node{
public:
	int x;
	node* next;
	node(int x1 = 0, node* n1 = NULL){
		next = n1;
		x = x1;
	}
};

class linkedList
{
private:
	node* head;
public:
	linkedList(node* h = NULL){
		head = h;
	}
	void setHead(node* h){
		head = h;
	}
	node* getHead(){
		return head;
	}
	void insertAtHead(int x){
		node* temp = new node(x);
		temp->next = this->head;
		this->head = temp;
	}
	void insertAtLast(int x){
		node* temp = new node(x);
		node* ptr = this->head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	void insertAtMiddle(int x){
		if(this->head == NULL){
			insertAtHead(x);
			return;
		}
		else if(this->head->next == NULL){
			insertAtLast(x);
			return;
		}
		else{
			node* temp = new node(x);
			// two pointer approach. Or hare and tortoise approach.
			node* slow = this->head; // position 1.
			node* fast = this->head->next; // position 2.
			while(fast!=NULL && fast->next != NULL){
				fast = fast->next->next;
				slow = slow->next;
			}
			temp->next = slow->next;
			slow->next = temp;
			slow->next = temp;
		}		
	}
	void insertAtPositionAfter(int x, int pos){
		if(pos <= 0 || this->head == NULL){
			insertAtHead(x);
			return;
		}
		// calculate length of linked list.
		node* ptr = this->head;
		int c = 1;
		while(ptr->next != NULL){
			ptr = ptr->next;
			c++;
		}
		if(pos >= c){
			insertAtLast(x);
			return;
		}
		else{
			ptr = this->head;
			c = 1;
			while(c != pos){
				c++;
				ptr = ptr->next;
			}
			node* temp = new node(x);
			temp->next = ptr->next;
			ptr->next = temp;
			return;
		}
	}
	void deleteATHead(){
		if(this->head == NULL){
			return;
		}
		else{
			node* ptr = this->head;
			this->head = this->head->next;
			delete ptr;
		}
	}
	void deleteATLast(){
		if(this->head == NULL){
			return;
		}
		else{
			node* ptr = this->head;
			node*prev = NULL;
			while(ptr->next != NULL){
				prev = ptr;
				ptr = ptr->next;
			}
			if(prev == NULL){
				delete ptr;
				head = NULL;
				return;
			}
			else{
				prev->next = ptr->next;
				delete ptr;
				return;
			}
		}
	}
	void deleteATMid(){
		if(this->head == NULL){
			return;
		}
		else{
			// calculate length.
			// even => length/2 position delete. odd => length+1/2	positon delete.
			// iterate through positons then delete it.
		}
	}
	void deleteATPosition(int pos);
	void print(){
		node* n = head;
		while(n!=NULL){
			cout << n->x << " -> ";
			n = n->next;
		}
		cout << "X" << endl;
	}
	
};

int main(){
	linkedList ll;
	node* head = new node(1);
	ll.setHead(head);
	ll.insertAtHead(2);
	ll.insertAtHead(5);
	ll.insertAtLast(3);
	ll.insertAtLast(4);
	ll.print();
	ll.insertAtMiddle(45);
	ll.print();
	ll.insertAtMiddle(46);
	ll.print();
	ll.insertAtPositionAfter(47, 4);
	ll.print();
	return 0;
}