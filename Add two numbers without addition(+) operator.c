#include <stdio.h>
#include <stdlib.h>

void main()

{
    int first_num, second_num;
    printf("Enter the two numbers to be added: ");
    scanf("%d %d",&first_num,&second_num);
    
    //method1 
    printf("Sum of the two numbers is %d\n", - ( - first_num - second_num ));
    
    //method2 
    printf("Sum of the two numbers is %d\n", first_num - ( -second_num ));
    
    //method3
    printf("Sum of the two numbers is %d\n", abs( - first_num - second_num ));
    
    //method4
    printf("Sum of the two numbers is %d\n", first_num - (~second_num) - 1 );
}