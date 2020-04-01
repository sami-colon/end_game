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

node* getLocation(node* head, int x, node* sorted){
	if(head == NULL)
		return NULL;
	while(head != sorted){
		if(head->data <= x && head->next->data > x){
			return head;
		}
		head = head->next;
	}
	return NULL;
}

node* insertionSort(node* head){
	if(head == NULL || head->next == NULL)
		return head;
	node* ptr = head->next, *prev = head;
	node* sorted = head;
	while(ptr!=NULL){
		node* key = ptr;
		if(prev->data > key->data){
			node* loc = getLocation(head, key->data, sorted);
			if(loc == NULL){
				// head is changed;
				prev->next = key->next;
				key->next = head;
				head = key;
			}
			else{
				prev->next = key->next;
				key->next = loc->next;
				loc->next = key;
			}
		}
		else{
			sorted = sorted->next;
		}
		prev = sorted;
		ptr = sorted->next;
	}
	return head;
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
	head = insertionSort(head);
	print(head);
	return 0;
}