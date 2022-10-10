/* Description: A program to check whether the input
 * integer number is positive or negative. 
*/
#include <stdio.h>
 
void main()
{
    int num,attempt;

    start:
    printf("Enter a number: \n");
    scanf("%d", &num);
    
    printf("You have entered %d number to check whether the number is positive or negative\n",num);
    
    if (num > 0)
        printf("%d is a positive number \n", num);
    else if (num < 0)
        printf("%d is a negative number \n", num);
    else
        printf("0 is neither positive nor negative");

    printf("Press 1 if you want to check another number\n");
    scanf("%d",&attempt);

    if (attempt==1)
    {
        goto start;
    }
    else{printf("Thank you for using this programme!!!");}

}
