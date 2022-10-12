#include<stdio.h>
#include<conio.h>
void main()
{
    int n,l,t;
    printf("Enter a number : ");
    scanf("%d",&n);
    for(l=1,t=n/10;t!=0;t/=10,l*=10)
    ;
    printf("\nThe pattern\n");
    for(t=n;t!=0;t%=l,l/=10)
        printf("\n%d",t);
}
