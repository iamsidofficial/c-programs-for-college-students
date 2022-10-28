// find the permutation of character in string

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *a, char *b);
void permute_char(char *value, int start, int end);

int main(){
    char *value;

    // allocating 1024 bytes to value variable
    value = (char *) malloc(sizeof(char) * 1024);
    printf("Enter any thing to permute: ");
    // will get input until user press enter 
    // or string length is equal to 1023 
    // 1 byte for '\0' so 1023 + 1 = 1024
    scanf("%1023[^'\n']",value);

    // reallocating only required memory to value variable
    value = (char *) realloc(value ,sizeof(char) * strlen(value));

    // initialization of permutation recursion
    permute_char(value, 0,strlen(value)-1);

    // otherwise shows % at the end of program in zsh terminal (not required)
    printf("\n");
    free(value);
    value = NULL;
    return 0;
}

void permute_char(char *value, int start, int end){
    if(start == end){
        printf("%s\t",value);
    }else{
        for(int i = start; i<= end; i++){

            swap(value+start, value+i);
            // can also be written as like below
            // swap(&value[start], &value[i]);
            
            permute_char(value, start+1, end);

            // backtrack
            swap(value+start, value+i);

        }
    }
    
}

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}