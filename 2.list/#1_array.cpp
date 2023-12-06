#include<stdio.h>
#include<stdlib.h>

int n;
int arr[6] = {1,2,3,4,5,6};

void insert_arr(int x,int p){
    for(int i = n-1; i >= p; i--){
        arr[i] = arr[i+1];    
    }
    arr[p] = x;
    n = n + 1;
}

void delete_arr(int* arr,int p){
    int index = i
	for(int i = 0; i< n-1; i++){
    	*(arr + i) = *(arr+(i+1));
	}
	n = n-1;
}

int retieve(int p){
    return arr[p];
}

int locate(int x){
    for(int i = 0; i < n; i++){
        if(arr[i] == x) return i;
    }
    return -1;
}

void makeNull(){
    n = 0;
}

int next(int p){
    if(0 <= p && p < n) return p++;
    return -1;
}

int prev(int p){
    if(p > 0 && p < n) return p--;
    return -1;
}

int main(){
	int n= 6;
    delete_arr(arr,3);
    for(int i = 0; i< n; i++){
    	printf(" %d ",arr[i]);
	}
    return 0;
}
