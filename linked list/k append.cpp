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

node* kappend(node* head, int n, int k){
	if(head == NULL || head->next==NULL || k>=n) return head;
	node* fast = head;
	for(int i=1; i<=k; i++)
		fast = fast->next;
	node* slow = head;
	while(fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	node* ptr = slow->next;
	slow->next = NULL;
	fast->next = head;
	return ptr;
}

int main(){
	int n;
	cin >> n;
	node* head = NULL;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		head = insertBack(head, x);
	}
	int k;
	cin >> k;
	head = kappend(head, n, k);
	print(head);
	return 0;
}