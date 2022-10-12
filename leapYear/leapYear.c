#include<stdio.h>
int main()
{
    int year;
    printf("Enter any Year:");
    scanf("%d",&year);
    if(year%4==0 && year%100!=0 || year%400==0)
        printf("the year %d is leap year",year);
    else
        printf("the year %d is not leap year",year);
}
