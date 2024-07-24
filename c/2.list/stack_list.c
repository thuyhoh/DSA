#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}Node;

Node* Stack = NULL;

Node* makeNode(int v){
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    return p;
}

void add_elm(Node* stack, int v){
    if(stack == NULL){
        stack = makeNode(v);
    }
    else{
        Node*p = makeNode(v);
        p->next = stack;
        stack = p;
        free(p);
    }
}

int isempty(Node* stack){
    return (stack == NULL)? 1: 0;
}

int gettop(Node* stack){
    if(isempty(stack)) {
        printf("stack empty");
        return 0;
    }else{
        return stack->val;
    }
}

int pop(Node* stack){
    if(isempty(stack)){
        printf("stack is empty");
        return 0;
    }else{
        int pop_val = stack->val;
        Node* p = stack;
        stack = stack->next;
        free(p);
        return pop_val;
    } 
}



int main(void){


    return 0;
}