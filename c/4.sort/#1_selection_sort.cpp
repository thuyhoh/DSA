#include<stdio.h>

void selection_sort(int a[],int n){
	for(int k = 0; k < n;  k++){
		int min = k;
		for(int j = k+1; j < n; j++){
			if(a[min]>a[j]) min == j;
		}
		int tmp = a[min];
		a[min] = a[k];
		a[k] = tmp;
	}
}




int main(){
	int a[]={6,1,4,6,8,3,5,0,7};
	selection_sort(a,9);
	for(int i = 0; i< 9; i++){
		printf("%d ",a[i]);
	}
}
