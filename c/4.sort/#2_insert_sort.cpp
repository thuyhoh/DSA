#include<stdio.h>

void insert_sort(int a[], int n){
	for(int k = 1; k < n; k++){
		int last = a[k];
		int j = k;
		while(j > 0 && a[j-1]>last){
			a[j] = a[j-1];
			j = j - 1;
		}
		a[j] = last;
	}
}

int main(){
	
}
