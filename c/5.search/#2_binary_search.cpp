#include<stdio.h>

int binary_search_recursive(int x[], int left, int right, int Y){
	if(left == right){
		if(x[left] == Y) return left;
		return -1;
	}
	int middle = (left + right)/2;
	if(x[middle] == Y) return middle;
	if(x[middle] < Y) return binary_search_recursive(x, middle+1, right, Y);
	return binary_search_recursive(x, left, middle-1, Y);
}

int binary_search_nonrecursive(int a[], int n, int k){
	int max = (n-1);
	int min = 0;
	int mid;
	int i = 0;
	while(max >= min){
		mid = (max + min)/2;
		i++;
		if(a[mid] == k){
			return mid;
		}else if(k > a[mid]) max = mid - 1;
		else min = mid + 1;
	}
	return -1;
}

int main(){
	int a[5]  = {1,2,3,4,5};
	printf("%d",binary_search_recursive(a,0,5,4));
}
