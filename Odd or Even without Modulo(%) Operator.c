// Program to Find whether a Integer is Odd or Even without a Modulo(%) operator


#include<stdio.h>                      

void main()
{
    int number;	

    printf("Enter a number to check whether it is \"even\" or \"odd\"\n");
    scanf("%d", &number);						    

    if( (number/2) * 2 == number)
        printf("\nEntered number is Even");
    else
        printf("\nEntered number is Odd");

}

/*
    Logic : If we divide an Even number by “2” then the result will be a whole number
	    and multipling the result with “2” we should be getting the actual number back,
            whereas when we divide a Odd number by “2” the result will be fraction and 
            when we multiply the result with “2” we will not be getting the same number again.
*/