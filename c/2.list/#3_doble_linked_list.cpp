#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	node* prev;
	node* next;
}Dnode;

Dnode* first;
Dnode* last;

Dnode* makeNode(int v){
	Dnode* p = (Dnode*)malloc(sizeof(Dnode));
	p->value = v;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void removelist(Dnode* p){
	if( p == NULL) return;
	if(first == last && p == first){
		first = NULL; last = NULL;
		free(p);
	} 
	if(p == first){
		first = p->next; first->prev = NULL;
		free(p);
		return;
	}
	if(p == last){
		last = p->prev; last->next == NULL;
		free(p); return;
	}
	p->prev->next = p->next; p->next->prev = p->prev; free(p);
}

void insertlast(int x){
	Dnode* q = makeNode(x);
	if(first == NULL && last == NULL){
		first = q;
		last = q;
		return;
	}
	q->next = last;
	last->next = q;
	last = q;
}

void insertbefore(int v,int u){
	
}

void insertafter(int v,int u){
	
}


void printlist(){
	Dnode* p = first;
	while(p != last){
		printf(" %d ",p->value);
		p = p->next;
	}
	printf(" %d ",last->value);
}



int main(){
	first = NULL;
	last = NULL;
	for(int i = 0; i< 10;i++){
		insertlast(i);
	}
	printlist();
	
	return 0;
}
