#include<stdio.h>
void main()
{
char str[20];
int n,i,flag=0;
printf("Enter the string:");
gets(str);
n=strlen(str); /*calculate string length*/
/* Loop to check the characters*/
for(i=0;i<n/2;i++)
{
if(toupper(str[i])!=toupper(str[n-1-i]))
{
  flag=1;
  break;
 }
}
/* Check the result*/
if(flag==0)
printf("\n\tThe string %s is a palindrome",str);
else
printf("\n\tThe string %s is not a palindrome",str);
}
