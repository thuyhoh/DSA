#include<bits/stdc++.h>
#include<vector>
#include<array>

using namespace std;

template <class T>
void print_vector(vector<T>VectorA, string Name){
	cout << "Vector "<< Name << ": "<< endl;
	for(int i = 0; i< VectorA.size(); i++){
		cout << VectorA[i] <<", ";
	}
	cout << endl;
}

template<class T>
void inforCapacity(vector<T> a){
	if(!a.empty()){
		cout << "front: " << a.front()<<"\t";
		cout << "back: " << a.back() <<"\t\n";
	}
	cout <<"size" << (int)a.size()<< endl;
	cout << "capacity" << (int)a.capacity()<<endl; // tra ve kich thuoc cua vector do 
	cout << "max_size" << (int)a.max_size() <<endl;// tra ve so luong phan tu toi da
	cout <<"is empty" << a.empty() << endl;	// kiem tra xem vector co trong hay ko
}

//template <class T>

int main(){
//============khai bao vector
	vector<int> va;//khai bao vec tor
	print_vector(va,"va");
	vector<int> vb(4,10);// khai bao vector co 4 phan tu 10 
	print_vector(vb,"vb");
	vector<int> vc(vb.begin()+2,vb.end());// khai bao vecto bat dau tu vb[2] -> vb.size()
	print_vector(vc,"vc");
	vector<int>vd(vc); // khai bao vector vd giong voi vc
	print_vector(vd,"vd");
	int arr[5]={0,1,2,3,4};// khai bao vector thongn qua mang
	vector<int>ve(arr,arr+sizeof(arr)/sizeof(int));
	print_vector(va,"va");
	
//===========
	vector<int> a(3,0);
	vector<int> b(5,0);
	vector<int> c(5);
	for(int i = 0; i< a.size();i++) {
		a[i] = (i + 1)*2;
	}
	for(int i = 0; i< b.size(); i++){
		b.at(i) = (i+1)*3;
	}
	c = {1,2,3,4,5,6};
	print_vector(a,"a");
	print_vector(b,"b");
	print_vector(c,"c");
	
	b = a;
	a = vector<int>();
	cout << "\nthe new contents \n";
	print_vector(a,"a");
	print_vector(b,"b");
	print_vector(c,"c");
	
	
//========================== 	insert and remove
	for(int i = 1; i< a.size(); i++){
		a.push_back(i*3);
	}
	print_vector(a,"a");
	
	a.pop_back();	print_vector(a,"a"); // lay phan tu cuoi day
	a.pop_back();	print_vector(a,"a");
	a.pop_back();	print_vector(a,"a");
	a.insert(a.begin(),30); 	print_vector(a,"a"); //them gia tri 30 o phan tu dau
	a.insert(a.begin()+2,2,45); 	print_vector(a,"a"); // them 2 gia tri 30 o phan tu thu 2
	a.clear(); // don sach a
	int b1[] = {1,2,3,4,5,6,7,8};
	a.insert(a.begin(),b1,b1+8); 	print_vector(a,"a"); // them phan tu tu mang
	a.erase(a.begin()+2,a.begin()+5); 	print_vector(a,"a"); // xoa phan tu bat dau tu a.begin()+2 -> a.begin()+5 
	a.erase(a.begin()+1);	print_vector(a,"a"); // xoa 1 phan tu
	
	
//======================= 	swap,assign
	int m[] = {1,2,3,4,5,6,7,8,9,10};
	a.assign(m,m+10);	print_vector(a,"a"); // gan gia tri cau a = m
	
	b.assign(5,10); 	print_vector(b,"b");
	
	c.assign(a.begin(),a.begin()+7);	print_vector(c,"c");
	
	cout<< "\n the new contents: \n";
	a.swap(b); // hoan doi gia tri cua a voi b
	print_vector(a,"a");	print_vector(b,"b");
	a.clear();
//======================   resize, data 
	
	
	a.assign(m,m+10); print_vector(a,"a");
	a.resize(6); 	print_vector(a,"a");
	a.resize(8,100); print_vector(a,"a");
	
	int *p = a.data();
	*p = 200;
	p[11] = 222;
	print_vector(a,"a");
	
	a.clear();

//======================= iterator
	a= {1,2,3,4,5,6,7,8};
	print_vector(a,"a");
	cout << "using iterator: ";
	vector<int>::iterator it; // khai bao con tro bo lap it
	for(it = a.begin(); it!= a.end(); it++){
		cout <<  *it << " ";
	}
	cout << endl;
	
	cout <<"\nusing reverse iterator: ";
	vector<int>:: reverse_iterator rit; // khai bao con troo bo lap dao rit
	for(rit = a.rbegin(); rit != a.rend(); rit++){
		cout<< * rit<< " ";
	}
	cout << endl;
	
	
	return 0;
	
}
