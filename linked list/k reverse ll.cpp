#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int x):data(x){
		next = NULL;
	}
};

node* insertAtHead(int x, node* head){
	node* temp = new node(x);
	temp->next = head;
	return temp;
}


node* insertAtBack(int x, node* head){
	node* temp = new node(x);
	if(head){
		node* ptr = head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next = temp;
		return head;
	}
	return temp;
}


void print(node* head){
	if(head){
		while(head!=NULL){
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
}

node* reverse(node* head){
	if(head==NULL || head->next==NULL)
		return head;
	node* curr = head;
	node* prev = NULL;
	while(curr!=NULL){
		node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

node* reverseLinkedList(node* head, int n ,int k){
	node* prev_head = head;
	node* prev_tail = head;
	node* curr_head;
	node* ans = NULL;
	for(int i=1; i<=n; i+=k){
		curr_head = prev_head;
		node* curr_tail = curr_head;
		for(int j=1; j<k; j++){
			curr_tail = curr_tail->next;
		}
		prev_head = curr_tail->next;
		curr_tail->next = NULL;
		node* temp = reverse(curr_head);
		if(ans)
			prev_tail->next = temp;
		else
			ans = temp;
		prev_tail = curr_head;
	}
	return ans;
}

int main(){
	int n, k;
	cin >> n >> k;
	node* head = NULL;
	for(int i=0; i<n; i++){
		int x; cin >> x;
		head = insertAtBack(x, head);
	}
	head = reverseLinkedList(head, n, k);
	print(head);
	return 0;
}
