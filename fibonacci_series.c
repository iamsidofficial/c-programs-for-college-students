/* Fibonacci series */
#include<stdio.h> 
void main()
{
int f1=0,f2=1,f3,i,n;
printf("Fibonacci series");
printf("\nEnter N value");
scanf("%d",&n);
printf("\nThe Fibonacci Series is:");
printf("%d %d",f1,f2);
for(i=1;i<=n-2;i++)
 {
  f3=f1+f2;
  printf(" %d",f3);
  f1=f2;
  f2=f3;
 }
}
