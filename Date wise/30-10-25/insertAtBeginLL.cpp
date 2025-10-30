#include<iostream>
using namespace std;

struct Node{
	int val;
	Node* next;
};

Node* create(int a){
	Node* n = new Node();
	n->val = a;
	n->next = NULL;
	return n;
}

Node* insertAtBegin(Node* head, int x){
	Node* n = create(x);
	n->next = head;
	head = n;
	return head;

}
Node* insertAtEnd(Node* head, int x){
    Node* n = create(x);
    if(head == NULL){
        return n;
    }
    
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    return head;
}

void print(Node* head){
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){
	Node* head = create(10);
	Node* a = create(20);
	Node* b = create(30);
	Node* c = create(40);

	head->next = a;
	a->next = b;
	b->next = c;

	cout<<"before Insertion: ";
	print(head);

	head = insertAtBegin(head, 50);

	cout<<"after insertion: ";
	print(head);

	cout<<"third insertion: ";
	head = insertAtBegin(head, 60);
	print(head);

    cout<<"insertion at end: ";
    head = insertAtEnd(head, 70);
    print(head);

	return 0;
	
}









