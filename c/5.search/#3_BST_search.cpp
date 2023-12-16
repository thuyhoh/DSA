#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
	int key;
	struct BST* leftchild;
	struct BST* rightchild;
}Node;

Node* makeNode(int v){
	Node* p = (Node*)malloc(sizeof(Node));
	p->key = v;
	p->leftchild = NULL;
	p->rightchild = NULL;
	return p;
}

Node* insert(Node* r, int v){
	if(r == NULL) {
		r = makeNode(v);
	}else if(r->key > v){
		r->leftchild = insert(r->leftchild,v);
	}else if(r->key < v){
		r->rightchild = insert(r->rightchild,v);
	}
	return r;
}

Node* search(Node* r, int v){
	if(r == NULL) return NULL;
	if(r->key == v) return r;
	else if(r->key > v) return search(r->leftchild,v);
	return search(r->rightchild,v);
}

Node* findmin(Node* r){
	if(r == NULL) return NULL;
	Node* lmin = findmin(r->leftchild);
	if(lmin!= NULL) return lmin;
	return r;
}

Node* del(Node* r, int v){
	if(r == NULL) return  NULL;
	else if(v < r->key) r->leftchild = del(r->leftchild,v);
	else if(v > r->key) r->rightchild = del(r->rightchild,v);
	else{
		if(r->leftchild != NULL && r->rightchild != NULL){
			Node* tmp = findmin(r->leftchild);
			r->key = tmp->key; r->rightchild = del(r->rightchild, tmp->key);
		}else{
			Node* tmp = r;
			if(r->leftchild == NULL) r= r->rightchild;
			else r = r->leftchild;
			free(tmp);
		}
	}
	return r;
}

void inorder(Node* r){
	if( r == NULL) return;
	inorder(r->leftchild);
	printf(" %d ",r->key);
	inorder(r->rightchild);
}

int main(){
	Node* root;
	root = NULL;
	root = insert(root,1);
	root = insert(root,3);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,5);
	
	root = del(root,2);
	
	inorder(root);
}
