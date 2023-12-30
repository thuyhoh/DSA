#include<stdio.h>
#include<stdlib.h>

typedef struct Bnode{
	int id;
	struct Bnode* leftchild;
	struct Bnode* rightchild;
}BNode;
BNode* root;

BNode* makeNode(int v){
	BNode* p = (BNode*)malloc(sizeof(BNode));
	p->id  = v;
	p->leftchild = NULL;
	p->rightchild = NULL;
	return p;
}

void inorder(BNode* r){
	if( r == NULL) return;
	inorder(r->leftchild);
	printf(" %d ",r->id);
	inorder(r->rightchild);
}

void preorder(BNode* r){
	if( r == NULL) return;
	printf(" %d ",r->id);
	preorder(r->leftchild);
	preorder(r->rightchild);
}

void postorder(BNode* r){
	if( r == NULL) return;
	postorder(r->leftchild);
	postorder(r->rightchild);
	printf(" %d ",r->id);
}

int count(BNode* r){
	if( r== NULL ) return 0;
	return 1+count(r->leftchild)+count(r->rightchild);
}
int main(){
	
	
	return  0;
}
