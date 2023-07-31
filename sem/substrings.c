#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int * ret = malloc(sizeof(int) * 30);

    int window_size = wordsSize * strlen(words[0]);
    
    if(window_size > strlen(s))
    {
        *returnSize = 0;
        return ret;
    }

    int act = 0;

   return ret;
}