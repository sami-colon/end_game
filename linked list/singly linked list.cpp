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

node* merge(node* a, node* b);

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
	void deleteATPosition(int pos){
		if(this->head == NULL) return;
		else{
			int len = 1;
			node* temp = head;
			while(temp != NULL){
				len++;
				temp = temp->next;
			}
			if(pos > len){
				return;
			}
			else{
				len = 1;
				temp = head;
				node* prev = NULL;
				while(len != pos){
					len++;
					prev = temp;
					temp = temp->next;
				}
				if(prev != NULL)
					prev->next = temp->next;
				else
					head = NULL;
				delete temp;
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
			int pos = 1;
			node* temp = this->head;
			while(temp!=NULL){
				temp = temp->next;
			}
			pos = pos%2==0?pos/2:(pos+1)/2;
			deleteATPosition(pos);
		}
	}
	bool searchUsingRecursion(int x, node* curr){
		if(curr == NULL){
			return false;
		}
		if(curr->x == x){
			return true;
		}
		else{
			return searchUsingRecursion(x, curr->next);
		}
	}
	void getInput(){
		int data;
		cin >> data;
		while(data != -1){
			if(this->head == NULL){
				node* temp = new node(data);
				this->setHead(temp);
			}
			else
				this->insertAtLast(data);
			cin >> data;
		}
		return;
	}
	void print(){
		node* n = head;
		while(n!=NULL){
			cout << n->x << " -> ";
			n = n->next;
		}
		cout << "X" << endl;
	}
	friend istream& operator>>(istream &is, linkedList ll);
	friend ostream& operator<<(ostream &os, linkedList ll);	
	void reverse(){
		node* prev = NULL;
		node* curr = this->head;
		while(curr != NULL){
			node* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		this->head = prev;
	}
	void reverseUsingRecusrion(node* curr, node* prev=NULL){
		if(curr == NULL){
			this->head = prev;
			return;
		}
		else{
			node* next = curr->next;
			curr->next = prev;
			reverseUsingRecusrion(next, curr);
			return;
		}
	}
	int getMiddleElement(){
		if(this->head == NULL) return -1;
		if(this->head->next == NULL) return head->x;

		// using runner approach.
		node* slow = this->head;
		/* for 1st mid element. */
		//node* fast = this->head->next;
		/* for 2nd mid element. */
		node* fast = this->head;
		while(fast!=NULL && fast->next!=NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow->x;
	}
	int getKthElementFromEnd(int k){
		int c=1;
		node*fast = this->head, *slow = this->head;
		while(c!=k && fast!=NULL){
			c++;
			fast=fast->next;
		}
		if(fast==NULL){
			return -1;
		}
		while(fast->next!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
		return slow->x;
	}
	node* mergeSort(node* head){
		if(head==NULL || head->next==NULL)
			return head;
		else{
			// get middle element.
			node* mid;
			if(head->next == NULL)
				mid = head;
			else{
				node* slow = head;
				node* fast = head->next;
				while(fast!=NULL && fast->next!=NULL){
					slow = slow->next;
					fast = fast->next->next;
				}
				mid = slow;
			}
			node* a = head, *b = mid->next;
			mid->next = NULL;
			a = mergeSort(a);
			b = mergeSort(b);
			return merge(a, b);
		}
	}
};

istream& operator>>(istream &is, linkedList *ll){
	ll->getInput();
	return is;
}

ostream& operator<<(ostream &os, linkedList ll){
	ll.print();
	return os;
} 

node* merge(node* a, node* b){
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->x <= b->x){
		node* next = merge(a->next, b);
		a->next = next;
		return a;
	}
	else{
		node* next = merge(a, b->next);
		b->next = next;
		return b;
	}
}

int main(){
	linkedList ll;
	cin >> &ll;
	cout << endl << ll << endl;
	ll.setHead(	ll.mergeSort(ll.getHead()));
	cout << endl << ll << endl;
	return 0;
}

