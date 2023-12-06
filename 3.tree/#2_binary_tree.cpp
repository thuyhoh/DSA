#include<stdio.h>

typedef struct Bnode{
	int id;
	struct Bnode* leftchild;
	struct Bnode* rightchild;
}BNode;
BNode* root;

BNode* makeNode(int v){
	BNode
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
