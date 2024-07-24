#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
    struct node* prev;
}Node;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

Node* head;
Node* tail;

void addList(int v){
    Node* p = makeNode(v);
    if(head == NULL && tail == NULL){
        head = p;
        tail = p;
    }
    p->next = tail;
    tail->next = p;
    tail = p;
}

void printdblist(Node* head, Node* tail){
    Node* p = head;
    while(p != tail){
        printf("%d",p->val);
        p = p->next;
    }
}



int main(void){
    head = NULL;
    
    tail = NULL;
    int i; 
    for (i = 0; i< 10; i++){
        addList(i);
    }
    printdblist(head,tail);
    
    
    return 0;
}