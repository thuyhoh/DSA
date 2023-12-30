#include<bits/stdc++.h>

using namespace std;

template <class T>
class node
{
	T elem;
	node<T> *prev,*next;
	public:
		node(T x,node<T> *L=0,node<T> *R=0) {elem=x;prev=L;next=R;}
		T &getelem() {return elem;}
		node<T> *&getprev(){return prev;}
		node<T> *&getnext(){return next;}
		void setelem(T x) {elem=x;}
		void setprev(node<T> *p=nullptr) {prev=p;}
		void setnext(node<T> *p=nullptr) {next=p;}
};

template<class T>
class dlist_iterator
{
	node<T> *curr;
	public:
		dlist_iterator(node<T> *c=0){curr=c;}
		node<T> *getcurr() {return curr;}
		dlist_iterator &operator=(dlist_iterator<T> it) {this->curr=it.getcurr(); return *this;}
		bool operator!=(dlist_iterator<T> it) {return curr!=it.getcurr();}
		T &operator*() {return curr->getelem();}
		dlist_iterator operator++(int) {dlist_iterator it=curr;curr=curr->getnext(); return it;}
		dlist_iterator operator++() {curr=curr->getnext(); return curr;}
};



template<class T>
class dlist
{
	node<T> *head,*tail;
	unsigned int num;
	public:
		typedef dlist_iterator<T> iterator;
		typedef dlist_reverse_iterator <T> reverse_iterator;
		iterator begin(){return head;}
		iterator end(){return nullptr;}
		reverse_iterator rbegin(){return tail;}
		reverse_iterator rend(){return nullptr;}
		dlist() {num=0;head=tail=nullptr;}
		dlist(int k,T x) {num=0;head=tail=0; while(k--) push_back(x);} //tao lis k phan tu bang x
		bool empty() {return num==0;}
		unsigned size(){return num;}
		void push_back(T x) 
		{
			if(num==0) head=tail=new node<T>(x);
			else 
			{
				tail->setnext(new node<T>(x,tail,0));
				tail=tail->getnext();
			}
			num++;
		}
		void push_front(T x) 
		{
			if(num==0) head=tail=new node<T>(x);
			else 
			{
				head->setprev(new node<T>(x,0,head));
				head=head->getprev();
			}
			num++;
		}
		T &front() {return head->getelem();}
		T &back()  {return tail->getelem();}
		void pop_back()
		{
			if(num==0) return;
			if(num==1) head=tail=nullptr;
			else
			{
				tail=tail->getprev();
				tail->setnext(0);
			}
			num--;
		}		
		void pop_front()
		{
			if(num==0) return;
			if(num==1) head=tail=nullptr;
			else
			{
				head=head->getnext();
				head->setprev(0);
			}
			num--;
		}
};


int main(){
	int n,d=0;  //d dung dem so so 0 tan cung cua n!
	dlist<int> L(1,1);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		long long nho=0;
		for(auto z=L.rbegin();z!=L.rend();z++)
		{
			nho+=*z*i;
			*z=nho%10;
			nho/=10;
		}
		while(nho) {L.push_front(nho%10); nho/=10;}
		while(L.back()==0) {d++; L.pop_back();}
	}
	for(auto z:L) cout<<z;
	//for(dlist<int>::iterator it=L.begin();it!=L.end();it++) cout<<*it;
	cout<<string(d,'0');
	
	return 0;
}


