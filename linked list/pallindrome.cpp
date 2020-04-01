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

int getElement(node* head, int x){
	for(int i=1; i<x; i++){
		head = head->next;
	}
	return head->data;
}

string pallindrome(node* head, int n){
	if(n <= 1){
		return "True";
	}
	int start = 1, end = n;
	while(start < end){
		if(getElement(head, start) != getElement(head, end)){
			return "False";
		}
		start++;
		end--;
	}
	return "True";
}

int main(){
	node* head = NULL;
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		head = insertBack(head, x);
	}
	cout << pallindrome(head, n) << endl;
	return 0;
}