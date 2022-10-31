#include<stdio.h>
int main()
{
    int n, temp, count=0;
    printf("Enter a number: \n");
    scanf("%d", &n);
    temp=n;
    while(n!=0) {
        n/=10;
        count++;
    }
    printf("Number of digits in %d is %d", temp, count);
    return 0;
    }
