#include <stdio.h>
#define MAX 100

int Top = 0;
int stack[MAX];

void check_full_stack(int *stack){
    if((stack++)== NULL){

    }
}

void push(int* stack,int v){

}

int pop(int*stack){
    int result = *(stack+Top);
    Top--;
    return result;
}

int main(void){


}
