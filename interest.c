#include<stdio.h>
float interest(int P,float R, int N)
{
     float SI;
     SI=P*R*N/100.0;
     return SI;
}      
int main()
{
     int p,n,i;
     float r,Z;
     for(i=1;i<=3;i++)
     {
          printf("Enter Info for Set-%d",i);
          printf("\n-----------------------------\n");
          printf("Enter Principal Amount : ");
          scanf("%d",&p);
          printf("Enter Interest-Rate : ");
          scanf("%f",&r);
          printf("Enter Time Period : ");
          scanf("%d",&n);
          Z=interest(p,r,n);
          printf("\nSimple-Interest for Set %d : %.2f\n",i,Z);
          printf("\n-----------------------------\n");
     }
     return 0;
}