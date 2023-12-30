#include<bits/stdc++.h>
#include<list>
#include<array>
using namespace std;

void printList(list<int> ds, string name){
	cout << "List " << name;
	if(ds.empty()) cout <<" is empty";
	else{
		cout << "has "<<ds.size()<<" elements: ";
		list<int>:: iterator it;
		for(it = ds.begin(); it!= ds.end(); it++){
			cout << *it <<" ";
		}
	}
	cout << endl;
}

int main(){
//================	constructor; operator =; empty; size; begin; end; assign; swap; clear
	int myints[6] = { 11,22,33,44,55,66};
	list<int> a;
	list<int> b(4,10);
	list<int> c(b);
	list<int> d(myints,myints+6);
	list<int> e = d;
	list<int> f(b.begin(),b.end());
	printList(a,"a");	printList(b,"b"); 	printList(c,"c");
	printList(d,"d");	printList(e,"e");	printList(f,"f");
	
	cout <<"new" <<endl;
	a.assign(b.begin(),b.end());
	b.assign(7,55);
	c.assign(myints,myints+3);
	d.clear();
	e.swap(f);
	printList(a,"a");	printList(b,"b"); 	printList(c,"c");
	printList(d,"d");	printList(e,"e");	printList(f,"f");
	a.clear();
	b.clear();
	c.clear();
	d.clear();
	e.clear();
	f.clear();
	
//================	front; back; fush_front; push_back; pop_front; pop_back		
	a.assign(myints,myints+6);
	printList(a,"a");
	cout <<"\n access: \n";
	a.front() = 111;	printList(a,"a");//thay the pt dau la 111
	a.back() ==789;		printList(a,"a");//thay the pt cuoi la 789
	
	cout<<"\nPush\n";
	a.push_back(900);	printList(a,"a");//chen cuoi
	a.push_front(100);	printList(a,"a");//chendau
	
	cout<<"\nPop\n";
	a.pop_back();	printList(a,"a");//xoa phan tu cuoi
	a.pop_front();	printList(a,"a");//xoa phan tu dau
	a.clear();
	cout<<endl;
	
//================ insert	
	a.assign(myints,myints+6);
	printList(a,"a");
	
	list<int>::iterator it = a.begin();
	++it;// it dang tro den pt 22
	a.insert(it,100); 	printList(a,"a");// them 1 phan tu vao vi tri 22
	a.insert(it,3,300);	printList(a,"a");// them 3 phan tu  300 vao vi tri 22
	
	vector<int> myvector(2,400);
	++it;// chuyene den phan tu 33
	a.insert(it,myvector.begin(),myvector.end());// them myvector vao trong list truowc phan tu it
	printList(a,"a");
	a.clear();

//================= erase
	cout <<endl;
	list<int> mylist;
	for(int i = 1; i< 10; ++i){
		mylist.push_back(i*10);
	}	
	printList(mylist,"mylist");
//	
//	list<int>:: iterator it1, it2;
//	it1 = it2 = mylist.begin();
//	advance(it2,6);
//	++it1;
	
//	it1 = mylist.erase(it2);
//	printList(mylist,"mylist");
//	
//	it2 = mylist.erase(it2);
//	printList(mylist,"mylist");
//	++it1;
//	--it2;
//	mylist.erase(it1,it2);
//	printList(mylist,"mylist");
	
//===============
	for(int i = 10; i> 1; --i){
		mylist.push_back(i);
	}
	printList(mylist, "mylist");
	
	mylist.sort(); 		printList(mylist, "mylist");
	mylist.remove(5);	printList(mylist, "mylist");
	mylist.reverse(); 	printList(mylist, "mylist");
	
	int my[] = {1,2,5,9,8,7};
	list<int> mylist2(my,my+5);
	printList(mylist2,"mylist2");
	
	cout<<"\nsplice\n";
	it = mylist.begin();
	it++;
	mylist.splice(it,mylist2);
	printList(mylist, "mylist");
	printList(mylist2, "mylist2");
	
	cout<<"\nunipue\n";
	mylist.sort(); printList(mylist, "mylist");
	mylist.unique();printList(mylist, "mylist");
	

	
	return 0;
}
