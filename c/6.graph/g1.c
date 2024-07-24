#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// graph
// graph don vo huong 
// graph da vo huong 
// graph 

int countchar(char* s, char c){
    int cnt = 0, i = 0;
    while(*(s+i) != '\0'){
        if(*(s+i) == c) cnt++;
        i++;
    }
    return cnt;
}

void thongke(char* s, char* charresult, int* nums, int* returnSize){
    int i = 0;
    int j = 0;
    while(*(s+i) != '\0'){
        int tmp = i;
        char c = *(s+i);
        int k;
        for(k = 0; k < i;k++){
            if(*(s+k) == *(s+i)) i++;
        }
        if(tmp != i){
            continue;
        }else{
            charresult[j] = c;
            nums[j] = countchar( s,c);
            j++;
        }
        i++;
    }
    *returnSize = j;
}

//int firstUniqChar(char* s){
//	char* charresult = (char*)calloc(strlen(s),sizeof(char));
//	int* nums = (int*)calloc(strlen(s),sizeof(char));
//	int cnt;
//	thongke(s,charresult,nums,&cnt);
//	int i = 0;
//	for(; i< cnt; i++){
//		if(nums[i] == 1) break;
//	}
//	if(i == (cnt -1)){
//		if(nums[i] != 1) return -1;
//	}
//	int j = 0;
//	while(*(s+i) != *(s+j)){
//		j++;
//	}
//	free(charresult);
//	free(nums);
//	return i-1;
//}

char **Morse = (char**)malloc(sizeof(char*)*26);
*(Morse) = (char*)malloc(sizeof(char)* 4);
Morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char m[2][2] = {{".-1"},{"-.--"},{"---"},{"..."}};
int main(void){
    
    
    printf("%s",*(Morse + 2));
    return 0;
}
