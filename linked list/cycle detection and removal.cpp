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

node* detectAndRemoveCycle(node* head){
	if(head == NULL)
		return NULL;
	node* slow = head, * fast = head->next;
	while(slow->data != fast->data){
		slow = slow->next;
		fast = fast->next->next;
	}
	// slow and fast is pointing at same element.
	slow = head;
	// make slow to initial point.
	// initial to cycle point and fast to cycle point is same.(x == z)
	node* prev = fast;
	while(slow->data != fast->next->data){
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
	return head;
}

node* find(node* head, int x){
	while(head != NULL){
		if(head->data == x)
			return head;
		head = head->next;
	}
	return NULL;
}

int main(){
	node* head = NULL;
	int x;
	cin >> x;
	while(x!=-1){
		node* temp = find(head, x);
		if(temp == NULL){
			head = insertBack(head, x);
		}
		else{
			node* ptr = head;
			while(ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next = temp;
			break;
		}
		cin >> x;
	}
	head = detectAndRemoveCycle(head);
	print(head);
	return 0;
}