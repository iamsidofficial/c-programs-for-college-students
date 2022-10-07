#include<stdio.h>
void countsort(int a[],int n,int i)
{
    int count[10]={0},b[30],j;
    for(j=0;j<n;j++)
    {
        ++count[(a[j]/i)%10];
    }
    for(j=1;j<=9;j++)
    {
        count[j]=count[j]+ count[j-1];
    }
    for(j=n-1;j>=0;j--)
    {
        b[--count[(a[j]/i)%10]]=a[j];
    }
    for(j=0;j<n;j++)
    {
        a[j]=b[j];
    }    
}
int getmax(int a[],int n)
{
    int i=0;
    int max=a[0];
    for(i=1;i<n;i++)
    {
        if(max<a[i])
        max=a[i];
    }
    return max;
}
void radixsort(int a[],int n)
{
    int max=getmax(a,n),i;
    for(i=1;max/i>0;i=i*10)
    {
        countsort(a,n,i);
    }
}
int main()
{
        int a[30],count[10]={0},b[30],n,i;
    printf("\nEnter number of elements of array:\n");
    scanf("%d",&n);
    printf("\nEnter elements of array:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    radixsort(a,n);
    printf("\nArray after Sorting:");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
