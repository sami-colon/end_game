#include<iostream>
#include<unordered_map>
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

int findIntersection(node* head_n, node* head_m){
	if(head_n == NULL || head_m == NULL)
		return -1;
	unordered_map<int, int> m;
	while(head_n != NULL){
		m[head_n->data] = 1;
		head_n = head_n->next;
	}
	while(head_m != NULL){
		if(m[head_m->data] == 1)
			return head_m->data;
		head_m = head_m->next;
	}
	return -1;
}

int main(){
	int n, m;
	node* head_n=NULL, *head_m=NULL;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		head_n = insertBack(head_n, x);
	}
	cin >> m;
	while(m--){
		int x;
		cin >> x;
		head_m = insertBack(head_m, x);
	}
	cout << findIntersection(head_n, head_m) << endl;
	return 0;
}