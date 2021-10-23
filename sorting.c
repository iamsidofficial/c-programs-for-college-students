#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start,end;
double cpu_time_used;


void bubblesort(int *a,int n)
{
   int i, j;
   int swapped,temp;
    printf("\nThe array before sorting: ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
   for (i = 0; i < n; i++)
   {
     swapped = 0;
     for (j = 0; j < n-i-1; j++)
     {
        if (a[j] > a[j+1])
        {
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
           swapped = 1;
        }
     }

     if (swapped == 0)
        break;
   }

}


void cocktailsort(int *a,int n)
{
    int swapped = 1;
    int start = 0;
    int end = n-1;
     printf("\nThe array before sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
    while (swapped)
    {
        swapped = 0;
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swapped = 1;
            }
        }
     if (!swapped)
            break;
     swapped = 0;
     --end;

   for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swapped = 1;
            }
        }

         ++start;
    }

}


int partition (int *a, int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (a[j] < pivot)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return (i + 1);
}

void quicksort(int *a,int low,int high)
{
     if (low < high)
    {
        int pi = partition(a, low, high);
        printf("\nThe value of the first element is %d and the last element is %d\n",low,high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }

}



void insertionsort(int *a,int n)
{
     int i, key, j;
     printf("\nThe array before sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

void selectionsort(int *a,int n)
{
    int i, j, m;
     printf("\nThe array before sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[m])
            m = j;
        int temp=a[m];
        a[m]=a[i];
        a[i]=temp;
    }

}


void heapsort(int *a,int n)
{
     for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
   for (int i = n - 1; i > 0; i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a, i, 0);
    }
}


void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a, n, largest);
    }
}


int main()
{
    int *a,n,ch,i;

    while(1)
    {

    printf("\n");
    printf("\n---OPERATIONS!!--\n");
    printf("\n1.Modified Bubble Sort.\n2.Cocktail Shaker Sort.\n3.Quick Sort.\n4.Insertion Sort.\n5.Selection Sort.\n6.Heap Sort.\n7.Exit.\n");
    printf("\n");
    printf("\nEnter your choice ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nEnter size of the array ");
               scanf("%d",&n);
               a=(int*)malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                    a[i]=rand()%100;
                }
                start=clock();
               bubblesort(a,n);
               end=clock();
               cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
               printf("\nCPU TIME FOR BUBBLE SORT :%f\n",cpu_time_used);
               printf("\n");
               printf("\nThe array after sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
               break;

        case 2:printf("\nEnter size of the array ");
               scanf("%d",&n);
               a=(int*)malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                    a[i]=rand()%100;
                }
                start=clock();
               cocktailsort(a,n);
               end=clock();
               cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
               printf("\nCPU TIME FOR COCKTAIL SHAKER SORT SORT :%f\n",cpu_time_used);
               printf("\n");
               printf("\nThe array after sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
               break;

        case 3:
               printf("\nEnter size of the array ");
               scanf("%d",&n);
               a=(int*)malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                    a[i]=rand()%100;
                }
            printf("\nThe array before sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
                start=clock();
               quicksort(a,0,n-1);
               end=clock();
               cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
               printf("\nCPU TIME FOR QUICK SORT :%f\n",cpu_time_used);
               printf("\n");
                printf("\nThe array after sorting: ");
               for(int i=0;i<n;i++)
               printf("%d ",a[i]);
               break;

        case 4:printf("\nEnter size of the array ");
               scanf("%d",&n);
               a=(int*)malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                    a[i]=rand()%100;
                }
               start=clock();
               insertionsort(a,n);
                end=clock();
                cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
                printf("\nCPU TIME FOR INSERTION SORT :%f\n",cpu_time_used);
                printf("\n");
                printf("\nThe array after sorting: ");
                for(int i=0;i<n;i++)
                printf("%d ",a[i]);
                break;

        case 5:printf("\nEnter size of the array ");
               scanf("%d",&n);
               a=(int*)malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                    a[i]=rand()%100;
                }
                start=clock();
              selectionsort(a,n);
              end=clock();
               cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
               printf("\nCPU TIME FOR SELECTION SORT :%f\n",cpu_time_used);
               printf("\n");
               printf("\nThe array after sorting: ");
               for(int i=0;i<n;i++)
                printf("%d ",a[i]);
               break;

        case 6:printf("\nEnter size of the array ");
               scanf("%d",&n);
               a=(int*)malloc(n*sizeof(int));
                for(i=0;i<n;i++)
                {
                    a[i]=rand()%100;
                }
                printf("\nThe array before sorting: ");
               for(int i=0;i<n;i++)
               printf("%d ",a[i]);
               start=clock();
               heapsort(a,n);
               end=clock();
               cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
               printf("\nCPU TIME FOR HEAP SORT :%f\n",cpu_time_used);
               printf("\n");
               printf("\nThe array after sorting: ");
               for(int i=0;i<n;i++)
               printf("%d ",a[i]);
               break;

        case 7:exit(0);
               break;

        default:printf("Wrong choice!");
                break;
    }
    }
}

