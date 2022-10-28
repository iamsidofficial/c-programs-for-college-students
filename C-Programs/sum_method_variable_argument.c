// sum of all numbers in method dynamic number of parameters

#include<stdio.h>
#include<stdarg.h>

int sum_method(int total, ...);

int main(){

    
    int sum = sum_method(4,1,2,3,4);
    printf("The sum using variable argument method is %d",sum);
    printf("\n");
    return 0;
}

int sum_method(int total, ...){
    va_list ptr;
    va_start(ptr,total);

    int sum = 0;
    for(int i = 0; i<total; i++){
        sum += va_arg(ptr, int);
    }
    return sum;
}
