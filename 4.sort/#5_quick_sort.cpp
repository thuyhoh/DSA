#include<bits/stdc++.h>

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int partition(int a[], int l, int r, int index_pivot){
	int pivot = a[index_pivot];
	swap(a[index_pivot],a[r]);
	int store_index = l;
	for(int i = l; i<= r-1; i++){
		if(a[i]<pivot){
			swap(a[store_index],a[i]);
			store_index++;
		}
	}
	swap(a[store_index],a[r]);
	return store_index;
}

void quick_sort(int a[], int L,int R){
	if(L < R){
		int index = (L + R)/2;
		index = partition(a,L,R,index);
		if(L < index){
			quick_sort(a,L,index-1);
		}if(index < R)
			quick_sort(a,index+1, R);
	}
}



int main(){
	int a[6]= {20,25,88,5,7,9};
	quick_sort(a,0,6);
	for(int i = 1; i<7; i++){
		printf("%d ",a[i]);
	}

}
