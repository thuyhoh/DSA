#include<stdio.h>

void swap(int &a,int &b){
	int  tmp  = a;
	a = b;
	b = tmp;
}


// vun lai dong 
void heapify(int a[],int i, int N){
	// vun dong giua a[i], a[2i],a[2i+1]
	int left = 2*i;
	int right = 2*i + 1;
	int max = i;
	if(left <= N && a[left] > a[i])	max = left;
	if(right <= N && a[right] > a[max]) max = right;
	if(max != i){
		swap(a[i], a[max]);
		heapify(a, max, N);// goi de qui (recursive)
	}
}

// vun lai dong
void build_heap(int a[], int N){
	// vun tu dong con len den dong lon
	for(int i = N/2; i>= 1; i--){
		heapify(a,i,N);
	}
}

// xap xep mang tu 1->N
void heap_sort(int a[], int N){
	// index tu 1-> n
	build_heap(a,N);//chuyen day ban dau thanh day max-heap
	for(int i = N; i > 1; i--){
		swap(a[1], a[i]);
		heapify(a,1,i-1);
	}
}


int main(){
	
	int a[11] = {0,63,43,35,6,5,4,3,2,1,0};
	heap_sort(a,10);
	for(int i = 1; i < 11; i++){
		printf(" %d ",a[i]);
	}
	return 0;
}
