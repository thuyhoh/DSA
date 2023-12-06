#include <stdio.h>
#include <stdlib.h>

typedef struct Nodetype{
    int value;
    struct Nodetype *next; //pointer to the next element
}Node;

Node* first;

Node* makeNode(int v){
    Node* q = (Node*)malloc(sizeof(Node));
    q->value = v;
    q->next = NULL;
    return q;
}

Node* addlast(int v,Node* h){
    //creat a new node having value = v, insert this node at the end of list pointed by h
    Node* q = makeNode(v);
    if(h == NULL) return q;
    Node* p = h; 
    while(p->next != NULL){ // p point to the last node of the list
        p = p->next;
    }
    p->next = q;
    // return a pointer to the first node of the result list
    return h;
}

void printlist(Node* h){
    Node* p = h;                
    while(p != NULL){           
        printf(" %d ",p->value);    
        p = p->next;                
    }
}

Node* removelist(int v,Node* h){
	// remove a first node having value = v in the list pointed by list
	if(h == NULL) return NULL;
	
	if(h->value == v){
		Node* tmp = h;
		h = h->next;
		free(tmp);
		return h;	
	};
	
	Node* p = h;
	while(p->next != NULL){
		if(p->next->value == v){
			Node* tmp;
			tmp = p->next;
			p->next = tmp->next;
			free(tmp);
			return h;
		}
		p = p->next;
	}	
	// return the pointer to the first node of the resulting  list
	return h; 
}
Node* removelist_Recursive(int v,Node* h){
	//use recursive implementation
	if(h == NULL) return h;
	if(h->value == v){
		Node* tmp = h;
		h = h->next;
		free(tmp);
		return h;
	}
	h->next = removelist_Recursive(v,h->next);
	return h;	
}

Node* insertfirst(int v,Node* h){
	Node* p = makeNode(v);
	p->next = h;
	return p;
}



Node* insertbefor_recursive(int v, int u, Node* h){
	if(h == NULL) return NULL;
	if(h->value == u) {
		Node* tmp = makeNode(v);
		h = insertfirst(v,h);
		return h;
	}
	h->next = (v,u,h->next);
	return h;
}

Node* insertbefor(int v,int u, Node* h){
	
}

Node* insertafter_recursive(int v,int u,Node* h){
	if(h == NULL) return NULL;
	if(h->value == u){
		Node* p = makeNode(v);
		p->next = h->next;
		h->next = p;
		return h;
	}
	h->next = insertafter(v,u,h->next);
	return h;
}
Node* insertafter(int v,int u,Node* h){
	
}

void freelist(Node*h){
	if(h == NULL) return;
	Node* p =h;
	while(p!= NULL){
		Node* tmp;
		tmp = p;
		p = p->next;
		free(tmp);		
	}
	free(p);
}
void freelist_recursive(Node* h){
	while(h != NULL){
		freelist_recursive(h->next);
		free(h);
	}
}



int main(){
    first = NULL;
    first = addlast(5,first);
    first = addlast(6,first);
    first = addlast(7,first);
    printf("%d",first->next->next->value);
	return 0;
}
