#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <string.h>
int **t,**p;
int n;
int mcmt(int n,int arr[])
{
    //memset(t,0,sizeof(t));
    for (int d=1;d<n;d++){
        for (int i=1;i<=n-d;i++){
            int j=i+d,mn=INT_MAX;
            for(int k=i;k<=j-1;k++){
                int cost=(arr[i-1] * arr[k] * arr[j]) + t[i][k] + t[k+1][j];
                if (cost<mn){
                    mn=cost;
                    p[i][j]=k;
                }
            }
            t[i][j]=mn;
        }
    }
    printf("Tabulation: \n");
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++)
            if(i>j) printf("x\t");
            else printf("%d\t",t[i][j]);
        printf("\n");
    }
    printf("Parenthesizing Matrix:\n");
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++)
            if(i>j) printf("x\t");
            else printf("%d\t",p[i][j]);
        printf("\n");
    }
    return t[1][n];
}

void printParenthesis(int i, int j)
{
    if (i>=j){
        printf(" A%d ",i);
    }
    else{
        printf("(");
        printParenthesis(i,p[i][j]);
        printParenthesis(p[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    printf("Enter no. of matrices: ");
    scanf("%d",&n);
    int *arr=malloc((n+1)*sizeof(int));
    printf("Enter Dimensions: \n");
    for (int i=0;i<n+1;i++)
        scanf("%d",&arr[i]);
    t=(int**)calloc(n+1,sizeof(int*));
    p=(int**)calloc(n+1,sizeof(int*));
    for(int i=0;i<=n;i++){
        *(t+i)=(int*)calloc(n+1,sizeof(int));
        *(p+i)=(int*)calloc(n+1,sizeof(int));
    }
    printf("Optimal Multiplication Xost: %d\n",mcmt(n,arr));
    printf("Parenthesized:\n");
    printParenthesis(1,n);
    return 0;
}

/*
Output of the program for <13,5,89,3,34>

Enter no. of matrices: 4
Enter Dimensions:
13 5 89 3 34
Tabulation:
0       5785    1530    2856
x       0       1335    1845
x       x       0       9078
x       x       x       0
Parenthesizing Matrix:
0       1       1       3
x       0       2       3
x       x       0       3
x       x       x       0
Optimal Multiplication Xost: 2856
Parenthesized:
(( A1 ( A2  A3 )) A4 )
Process returned 0 (0x0)   execution time : 24.225 s
Press any key to continue.
*/
