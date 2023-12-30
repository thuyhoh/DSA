#include<bits/stdc++.h>
#include<math.h>

void seclection_sort(int *nums, int n){
    int min = 0;
    int i, j;
    for( i = 0; i< n; i++){
        for( j = i; j < n; j++){
            min = (min < nums[j])? :nums[j];

        }
        int tmp =  nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}

void insertion_sort(int* nums, int n){
    for(int i  = 1; i< n; i++){
        int j;
        for( j = i-1; j > 0; j--){
            if(nums[i] < nums[j]){
                nums[j] = nums[j+1];
            }
        }
        nums[j] = nums[i];
    }
}

// void pivot_index(int* a, int left, int right, int index_pivot){
//     int pivot = a[index_pivot];
//     for(int i = left)
// }

using namespace std;

int main(){
    float a= log2(5);
    cout <<  a;
    return 0;
}