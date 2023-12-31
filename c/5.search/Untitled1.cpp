#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void gen(char* filename, int n, int MAX_VALUE){
	srand(time(NULL));
	FILE*f = fopen(filename,"w");
	for(int i = 0; i <= n; i++){
		int x = rand()%MAX_VALUE+1;
		fprintf(f," %d ",x);
	}
	fprintf(f,"\n-1\n");
	for(int i = 1; i<= n; i++){
		int a = rand()%3;
		int k = rand()%MAX_VALUE;
		if(a == 0){
			fprintf(f,"insert %d\n",k);
		}else if (a == 1){
			fprintf(f,"remove %d\n",k);
		}else{
			fprintf(f,"find %d\n",k);
		}
	}
	fprintf(f,"*");
	fclose(f);
}

int main(){
	gen((char*)"text-10000.txt",10000,100000);
}
