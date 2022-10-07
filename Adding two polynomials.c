#include<stdio.h>
#include<math.h>
#include<stdlib.h>


struct poly
{
  float coef;
  int exp;
};


int main()
{
 struct poly *p1, *p2,*p3;

 int i;
 int deg1,deg2;
 int k=0,l=0;

 printf("Enter the highest degree of polynomial 1:");  //stores the degree of the polynomial
 scanf("%d",&deg1);
 p1 = (struct poly *)malloc(deg1 * 2 * sizeof(struct poly));

 for(i=0;i<=deg1;i++)  //taking input of first polynomial
 {

        printf("\nEnter the coefficient of x^%d :",i);
        scanf("%f",&(p1+i)->coef);


        (p1+k)->exp = i;
        k++;
 }
k = 0;

 printf("\nEnter the highest degree of polynomial 2:");    //taking input of second polynomial
 scanf("%d",&deg2);
 p2 = (struct poly *)malloc(deg2 * 2 * sizeof(struct poly));

 for(i=0;i<=deg2;i++)
{
       printf("\nEnter the coefficient of x^%d :",i);
       scanf("%f",&(p2+i)->coef);

	   (p2+k)->exp = i;
	   k++;
 }

  printf("\nThe first polynomial is 1 = %.1f ",(p1)->coef);  //to print the first polynomial

  for(i=1;i<=deg1;i++)
  {

        printf("+ %.1fx^%d",(p1+i)->coef,(p1+i)->exp);
  }

    printf("\n");

   printf("\nThe second polynomial is = %.1f ",(p2)->coef);  //to print the second polynomial

   for(i=1;i<=deg2;i++)
  {

      printf("+ %.1fx^%d",(p2+i)->coef,(p2+i)->exp);
  }

    printf("\n");

    p3 =  (struct poly *)malloc(deg1 * deg2 * 2 * sizeof(struct poly)) ; //allocating memory for the third polynomial to store the sum


    if(deg2>deg1)  //to add two polynomials
        {
             for(i=0;i<=deg1;i++)
              {
                (p3+l)->coef = (p2+i)->coef + (p1+i)->coef;
                (p3+l)->exp = (p2+i)->exp;
                l++;
              }

              for(i=deg1+1;i<=deg2;i++)
              {
                (p3+l)->coef = (p2+i)->coef;
                (p3+l)->exp = (p2+i)->exp;
                l++;
              }

        }
    else
      {
        for(i=0;i<=deg2;i++)
         {
           (p3+l)->coef= (p2+i)->coef + (p1+i)->coef;
           (p3+l)->exp= (p2+i)->exp;
           l++;
         }

        for(i=deg2+1;i<=deg1;i++)
        {
          (p3+l)->coef = (p1+i)->coef;
          (p3+l)->exp = (p1+i)->exp;
          l++;
        }
      }

  printf("\nThe sum of two polynomials is = %.1f",(p3)->coef);  //to print the sum of two polynomials
  for(i=1;i<l;i++)
      {
         printf("+ %.1fx^%d",(p3+i)->coef,(p3+i)->exp);
      }

      printf("\n");

  free(p1);
  free(p2);
  free(p3);
  return 0;

}
