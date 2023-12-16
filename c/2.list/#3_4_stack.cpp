#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000000

char s[M];

typedef struct stacknode{
	char c;
	struct stacknode* next;
}Node;

Node* top = NULL;

Node* makeNode(char c){
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->c = c;
	return p;
}

void push(char c){
	Node* p = makeNode(c);
	p->next = top;
	top = p;
}

char pop(){
	//lay 1 phan tu stack tra ve truong c
	char c = top->c;
	Node* tmp = top;
	top = top->next;
	free(tmp);
	return c;
	
}

int empty(){
	// return 1 if stack empty else return 0;
	return top == NULL; 
}

int match(char o, char c){
	if(o == '(' && c == ')') return 1;
	if(o == '{' && c == '}') return 1;
	if(o == '[' && c == ']') return 1;
	return 0;	
}

int check(char *s){
	for(int i = 0; i< strlen(s);i++){
		if(s[i] == '('|| s[i] == '['|| s[i] == '{'){
			push(s[i]);
	}else{
		if(empty() == 1) return 0;
		char o = pop();
		if(match(o,s[i]) == 0)  return 0;
		}
	}
	return empty();
}

int main(){
	scanf("%s",s);
	int ans = check(s);
	printf("%d",ans);
	return 0;
}
