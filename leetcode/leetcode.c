#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

char* reversePrefix(char* word, char ch) 
{
    int index = 0, i = 0;
    int n = strlen(word);
    char *ans = (char *)calloc(n,sizeof(char));
    for(i = 0; i < n; i++)
    {
          if(word[i] == ch)
            break;
          else
            index++;
    }
    if(index == n) return word;
    for(i = 0; i < n; i++)
            if(i < index)
                ans[i] = word[index-i];
            else
                ans[i] = word[i];
    return ans;
}
int main(void)
{
    
    void *pf = (void *)reversePrefix;
    printf("%d",sizeof(pf));
}