#include<stdio.h>
int main()
{
    int num;
    printf("enter any integer:");
    scanf("%d",&num);
    if(num%2==0)
    printf("the number %d is a composite number",num);
    else
    printf("the number %d is a prime number",num);
}