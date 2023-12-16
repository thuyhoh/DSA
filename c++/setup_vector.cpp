#include<bits/stdc++.h>

using namespace std;
template <class T>
class Vector{
	private:
		int cap, n;
		T* V;
	public:
		Vector(){
			cap = n = 0;
			V = 0;
		}
		Vector(int num);
		Vector(int k, T x);
		Vector& operator=(Vector a);
		~Vector();
		int capacity();
		int size();
		bool empty();
		void pop_back();
		T& back();
		void Push_back(T x);
		T& operator[](int k);
		void insert(int k, T x);
		void extend(int newcap);
		
		typedef T* iterator;
		iterator begin(){return V;};
		iterator end()	{return V+n;};
		void erase(iterator);
		
};

template <class T>
Vector<T>::Vector(int num){
	cap = n = num;
	V = new T[n];
	for(int i = 0; i< n; i++){
		V[i] = 0;
	}
}

template <class T>
Vector<T>::Vector(int k, T x){
	cap = n = k;
	V = new T[n];
	for(int i = 0; i< n; i++){
		V[i] = x;
	}
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector a){
	cap = a.capacity();
	n = a.size();
	if(cap) V = new T[cap];
	for(int i = 0; i< n; i++){
		V[i]  = a[i];
	}
	return *this;
}

template <class T>
Vector<T>::~Vector(){
	if(V) delete[] V;
}

template <class T>
int Vector<T>::capacity(){
	return cap;
}

template <class T>
int Vector<T>::size(){
	return n;
}

template <class T>
bool Vector<T>:: empty(){
	return n == 0;
}

template <class T>
void Vector<T>:: pop_back(){
	if(n > 0) n--;
}

template<class T>
T& Vector<T> :: back(){
	return V[n-1];
}

template<class T>
void Vector<T>::Push_back(T x){
	if(n == cap) extend(cap*2 + 5);
	V[n++] = x;
}

template <class T>
T& Vector<T>::operator[](int k){
	return V[k];
}

template <class T>
void Vector<T>:: insert(int k, T x){
	if(cap == n - 1) extend(cap*2 + 5);
	for(int i = n; i >= k; i--){
		V[i+1] = V[i];
	}
	V[k] = x;
	n++;
}

template <class T>
void Vector<T>::extend(int newcap){
	if(newcap < cap) return;
	cap = newcap;
	T* temp = new T[cap];
	for(int i = 0; i< n; i++){
		temp[i] = V[i];
	}
	if(V) delete[] V;
	V = temp;
}

template<class T>
void Vector<T>:: erase(iterator it){
	while(it + 1 != end()){
		*it = *(it+1);
		it++;
	}
	n--;
}

int main(){
	Vector<int> a;
	a.Push_back(3);
	printf("%d",a[0]);
	return 0;
}
