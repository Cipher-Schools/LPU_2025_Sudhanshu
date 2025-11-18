/**
 * Program to merge two sorted linked lists into a single sorted linked list.
 * TC: O(n + m) where n and m are the lengths of the two linked lists.
 */

#include<iostream>

using namespace std;
struct node{
    int data;
    node* next;
};

node* create(int val){
    node* n = new node{val, nullptr};
    return n;
}

void insertAtEnd(node** head, int val){
    node* n = create(val);
    if(*head == nullptr){
        // return n;
        *head = n;
        return;
    }
    node* t = *head;
    while(t->next != nullptr){
        t = t->next;
    }
    t->next = n;
    // return *head;
}
void display(node* head){
    while(head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return ;
}
node* combine(node* h, node* t){
    
    node* ret = create(0);
    node* q = ret;
    while(h != nullptr && t != nullptr){
        if(h->data < t->data){
            ret->next = h;
            ret = ret->next;
            h = h->next;
        }else{
            ret->next = t;
            ret = ret->next;
            t = t->next;
        }
    }
    if(h != nullptr){
        ret->next = h;
    }
    if(t != nullptr){
        ret->next = t;
    }
    return q->next;
    
}


int main(){
    node* head1 = nullptr;
    node* head2 = nullptr;
    for(int i=1;i<=10;i+=2){
        insertAtEnd(&head1, i*10);
    }
    for(int i=0;i<=10;i+=2){
        insertAtEnd(&head2, i*10);
    }
    cout<<"1st list: " ;
    display(head1);
    cout<<"2nd list: " ;
    display(head2);
    
    node* t = combine(head1, head2);
    display(t);
    return 0;
}













