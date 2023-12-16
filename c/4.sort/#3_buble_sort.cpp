#include<stdio.h>

void buble_sort(int a[], int n){
	int swapped;
	do{
		swapped = 0;
		for(int i = 0; i < n; i++){
			if(a[i]>a[i+1]){
				int tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;
				swapped = 1; 
			}
		}
	}while(swapped == 1);
}

int main(){

	return 0;
}
