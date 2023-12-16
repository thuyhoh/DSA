#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char * gcdOfStrings(char * str1, char * str2){
    if(str1 == NULL || str2 == NULL) return NULL;
    
    int len;
    len = (strlen(str1) < strlen(str2)) ? strlen(str1) : strlen(str2);
	char* result = (char*)malloc(sizeof(char)*len);
     
    int k = 0;
	for(int i = 0; i < len; i++){
    	if(*(str1+i) == *(str2+i)){
    		*(result+k) = *(str1+i); 
    		k++;
		}
	}
	return result;

}

int main(){
	char str1[] = "hello";
	char str2[] = "heybye";
	
	char* ans = gcdOfStrings(str1,str2);
	
	
	printf("%s",ans);
}

