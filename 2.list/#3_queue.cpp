#include<stdio.h>
#include<stdlib.h>

struct queueNode{
	int x,y;
	struct queueNode* next;
}Node;
Node* head;
Node* tail;
Node* start;
Node* target;
int visited[1000][1000];
int a,b,c;

Node* makeNode(int x,int y){
	Node* p = (Node*)malloc(sizeof(Node));
	p->x = x,
	p->y = y;
	p->next = NULL;
	return p
}
void push(Node* s){
	
}
Node* pop(){
	
}

int empty(){
	
}

int checkfinal(Node* s){
	if(s->x == c||s->y == c) return 1 
	return 0;
}

void solve(){
	for(int i = 0; i<1000; i++){
		for(int j = 0; j< 1000; j++){
			visited[i][j] = 0;
		}
	}
	head = NULL;
	tail = NULL;
	push(start);
	visited[0][0] = 1;
	while(!empty()){
		Node* s = pop();// trang thai hienj tai s->x,s->y
		
		Node* ns = NULL;
		// do vao binh 1
		if(visited[a][s->y] == 0){
			ns = makeNode(a,s->y);
			if(check(final(ns))) break;
			push(ns);
			visited[ns->x][ns->y] = 1;
		}
	}
	/// fill jug 2next state s->x,b
	if(visited[a->x][b] == 0){
		ns = makeNode(s->x,b);
		if(checkfinal(ns)){
			break;
		}
		push(ns);
		visited[ns->x][ns->y] = 1;
	}
	if (visited[0][a->y] == 0){
		ns = makeNode(0,s->y);
		push(ns);
	}
}
void pu

int main(){
	return 0;
}
