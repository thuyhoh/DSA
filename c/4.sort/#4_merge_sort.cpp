#include<stdio.h>

void merge(int a[], int Left, int Middle, int Right){
	int i = Left;
	int j = Middle + 1;
	int TA[Right];
	for(int k = Left; k <= Right; k++){
		if(i > Middle){
			TA[k] = a[j];
			j++;
		}else if(j > Right){
			TA[k] = a[i];
			i++;
		}else{
			if(a[i] < a[j]){
				TA[k] = a[i];
				i++;
			}else{
				TA[k]  = a[j];
				j++;
			}
		}
	}
	for(int k = Left; k <= Right; k++){
		a[k] = TA[k];
	}
}

void merge_sort(int a[], int Left, int Right){
	if(Left < Right){
		int Middle = (Left + Right)/2;
		merge_sort(a, Left, Middle);
		merge_sort(a, Middle+1, Right);
		merge(a, Left, Middle, Right);
	}
}

int main(){
	int a[] = {1,5,7,3,8,1,2,9,4};
	merge_sort(a,0,9);
	for(int i =1; i<=9; i++){
		printf(" %d ",a[i]);
	}
}
