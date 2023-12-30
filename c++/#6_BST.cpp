#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int d = 0, Node* l = NULL, Node* r = NULL){
		data = d;
		left = l;
		right = r;
	}
};

class BST{
	Node* root;
//	void Insert(Node*, int);
	Node* insert(Node* , int);
	bool search(Node*, int);
	void inorder(Node*);
	void preorder(Node*);
	void postorder(Node*);
	Node* findmin(Node*);
	Node* del(Node*, int);

	public:
		BST(){root = NULL;};
		void insert(int );
		bool search(int);
		void inorder();
		void preorder();
		void postorder();
		void del(int k);
};

//void BST::Insert(Node* &T, int k){
//	if(T == NULL) T= new Node(k);
//	else if(k ==T->data) return;
//	else if(k < T->data) Insert(T->left,k);
//	else Insert(T->right,k);
//}

Node* BST::insert(Node* T,int k){
	if(T == NULL) return T = new Node(k);
	else if(T->data > k){
		T->left = insert(T->left,k);
	}else if(T->data < k){
		T->right = insert(T->right, k);
	}
	return T;
}

void BST::insert(int k){
	root = insert(root,k);
}


void BST::inorder(Node* T){
	if( T == NULL) return ;
	inorder(T->left);
	cout << T->data;
	inorder(T->right);
}

void BST::inorder(){
	if(root == NULL){
		cout << "cay trong";
	}else inorder(root);
}

void BST::preorder(Node* T){
	if(T != NULL){
		cout <<T->data;
		if(T->left!= NULL){
			cout <<"\tleft: "<< T->left->data;
		}else cout<< "\tleft: NULL";
		if(T->right!= NULL){
			cout <<"\tright:"<< T->right->data;
		}else cout<< "\tright: NULL";
		cout<<endl;
		preorder(T->left);
		preorder(T->right);
	}
}




void BST :: preorder(){
	if(root == NULL) cout << "ko co gia tri";
	else preorder(root);
}




void OUT_ARRAY(int a[], int n){
	for(int i = 0; i< n; i++) cout << a[i] << " ";
	cout << "\n\n";
}

void BST::postorder(Node* T){
	if(T != NULL){
		postorder(T->left);
		postorder(T->right);
		cout << T->data << " ";
	}
}

void BST :: postorder(){
	if(root == NULL){
		cout << "caay trong";
	}else{
	postorder(root);
	}
}




bool BST::search(Node* T,int k){
	if(T == NULL) return false;
	if(k == T->data)  return true;
	else if (k < T->data) return search(T->left,k);
	else return search(T->right,k);
}

bool BST::search(int k){
	if(root == NULL) return false;
	else return search(root,k);
}

Node* BST::findmin(Node* r){
	if(r == NULL) return NULL;
	Node* lmin = findmin(r->left);
	if(lmin!= NULL) return lmin;
	return r;
}

Node* BST::del(Node* r, int v){
	if(r == NULL) return  NULL;
	else if(v < r->data) r->left = del(r->left,v);
	else if(v > r->data) r->right = del(r->right,v);
	else{
		if(r->left != NULL && r->right != NULL){
			Node* tmp = findmin(r->left);
			r->data = tmp->data; r->right = del(r->right, tmp->data);
		}else{
			Node* tmp = r;
			if(r->left == NULL) r= r->right;
			else r = r->left;
			free(tmp);
		}
	}
	return r;
}

void BST::del(int k){
	if(!search(k) || root == NULL) cout <<"khng co phan tu de xoa";
	else{
		cout << "xoa phan tu "<< k;
		root = del(root,k);
	}
	
}

int main(){
	BST root;
	
	root.insert(3);
	root.insert(5);
	root.insert(8);
	
	root.del(5);
	if(root.search(8)) cout<<"\n" << "co kq";
	else cout <<"\n" << " ko co kq";
	cout <<"\n"<<" ";
	root.inorder();
	return 0;
}
