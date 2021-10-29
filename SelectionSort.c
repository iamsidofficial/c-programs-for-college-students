#include<stdio.h>
void main()
{

    int a[20],i,j,n,temp,s,pos;
    printf("Enter n");
    scanf("%d",&n);
    printf("Enter elements in the array");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    /*using selection sort*/
    for(i=0;i<n;i++){
            s=a[i];
            pos=i;
        for(j=i;j<n;j++){
           if(a[j]<s)
           {
               s=a[j];
               pos=j;
           }
         }
         temp=a[i];
         a[i]=a[pos];
         a[pos]=temp;
        }

    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
