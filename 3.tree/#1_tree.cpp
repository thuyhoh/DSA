#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Tnode{
	int id;
	struct Tnode* leftmostchild;
	struct Tnode* rightsibling;
}Node;

Node* root;


Node* makeNode(int u){
	Node* p= (Node*) malloc(sizeof(Node));
	p->id = u;
	p->leftmostchild = NULL;
	p->rightsibling = NULL;
	return p;
}

Node* find(int v,Node* r){
	//return the point has id is v, in the root tree;
	if(r  == NULL) return NULL;
	if(r->id == v) return r;
	Node* p = r->leftmostchild;
	while(p != NULL){
		Node* q = find(v,p);
		if(q != NULL ) return q;
		p = p->rightsibling;
	}
	return NULL;
}


void insert(int u,int v){
	// tao motj nut con cos id bawng u chen vao cuoi nut con cos id bawngf v
	//tren cay co con tro laf root
	Node* r=find(v,root);
	Node* p=find(u,root);
	if(p!=NULL) return ;
	p= makeNode(u);
	if(r->leftmostchild == NULL){
		r->leftmostchild = p;
	}else{
		Node* h = r->leftmostchild;
		while(h->rightsibling != NULL){
			h=h->rightsibling;
		}
		h->rightsibling = p;
	}
}


void printTree(Node* r){
	if(r == NULL) return;
	printf(" %d ",r->id);
	for(Node* p=r->leftmostchild;p!=NULL;p=p->rightsibling){
		printf(" %d ",p->id);
	}
	printf("\n");
	for(Node* p=r->leftmostchild;p != NULL;p=p->rightsibling){
		printTree(p);
	}
}

int countNode(Node* r){
	// return the number of nodes in the tree rooted at r;
	if(r == NULL) return 0;
	Node* p = r->leftmostchild;
	int cnt = 1;
	while(p != NULL){
		cnt = cnt + countNode(p);
		p = p->rightsibling;
	}
	return cnt;
	
}

int countleaves(Node* r){
	// return the number of leaf nodes of the tree rooted at r
	if(r == NULL) return 0;
	int cnt = 0;
	if(r->leftmostchild == NULL) return cnt+1;	
	Node* p = r->leftmostchild;
	while(p != NULL){
		cnt = cnt +countleaves(p);
		p = p->rightsibling;
	}
	return cnt;
	 
}



int heightNode(Node* r){
	if( r == NULL ) return 0;
	int maxH = 0;
	for(Node* p = r->leftmostchild; p!= NULL; p = p->rightsibling){
		int h = heightNode(p);
		if(h > maxH) maxH=h;
	}
	return maxH + 1;
}
int height(int v){// height is the longest way from the node has id = v to the leaf
	// return the height of the node having id = v;
	Node* r = find(v,root);
	return heightNode(r);
}

int depthNode(int v,Node* r, int d){
	// d laf do sau cuar r tren cay goc root
	if(r ==  NULL) return -1;
	if(r->id == v) return d;
	for(Node* p = r->leftmostchild; p != NULL; p = p->rightsibling){
		if(p->id == v) return d+1;
		int rs = depthNode(v,p,d+1);
		if(rs>-1) return rs;
	}
	return -1;
	
}



int depth(int v){// depth is the way from the root's tree to the node has id = v
	// return the depth of the node  having id = v in the tree
	return depthNode(v,root,1);
}

void inorder(Node* r){
	if(r == NULL) return;
	Node* p = r->leftmostchild;// p tro vao nut goc r1;
	inorder(p);
	printf(" %d ",r->id);//tham nut goc
	if(p == NULL) return;
	p = p->rightsibling;// truy cap den goc r2
	while(p != NULL){
		inorder(p);// tham cay theo thu tu giua
		p = p->rightsibling;
	}
}

void preorder(Node* r){
	if(r == NULL) return;
	printf(" %d ",r->id);
	Node* p = r->leftmostchild;
	while(p != NULL){
		preorder(p);
		p = p->rightsibling;
	}
}

void postorder(Node* r){
	if(r == NULL) return;
	Node* p = r->leftmostchild;
	while(p != NULL){
		preorder(p);
		p = p->rightsibling;
	}
	printf(" %d ",r->id);
}



int main(){	
	root = NULL;
	
	root = makeNode(3);
	insert(6,3);
	insert(9,3);
	insert(8,6);
	insert(1,8);
	
	printTree(root);	
	return 0;	
}
