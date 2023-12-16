#include<stdio.h>
int  sequential_search(int x[], int L, int R, int Y){
	// return gia tri inxdex / x[index] = y
	for(int i = left; i< right; i++){
		if (x[i] == Y) return i;
	}
	return -1;// Y ko ton tai trong day
} 

int main(){
	
}
