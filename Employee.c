#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct employee
{
    char name[100],acc_num[100];
    int salary;
}name,acc_num,salary;
void main()
{
    struct employee *emp;
    int i,n;
    int max_sal=0,temp=0;

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    printf("The program execution begins at: %ld ms",start);

    printf("\n\n Enter the number of employees: ");
    scanf("%d",&n);
    emp =calloc(n,(sizeof(*emp)));

    printf("Enter the informations : \n");
    for(i=0;i<n;i++)
    {

        printf("Enter the employee Name:");
        scanf(" %s",&emp[i].name);
        printf("Enter the employee's Account Number:");
        scanf("%s",&emp[i].acc_num);
        printf("Enter the employee's Salary:");
        scanf("%d",&emp[i].salary);
        printf("\n");

    }

    max_sal = emp[0].salary;
    printf("\nThe details of the employee with highest salary are as follows:\n");
    for(i=1;i<n;i++)
    {
        if(max_sal<emp[i].salary)
        {
            max_sal = emp[i].salary;
            temp=i;
        }
    }

    printf("\n Name of the employee is: ");
    printf(" %s",emp[temp].name);
    printf("\n Account number is: ");
    printf(" %s",emp[temp].acc_num);
    printf("\n Salary is: ");
    printf("%d",emp[temp].salary);
    printf("\n");
    end = clock();
    printf("\n The program execution ends at: %ld ms",end);

    cpu_time_used = (double) (end - start) / CLOCKS_PER_SEC;
    printf ("\n Total CPU time taken to run the code in seconds is: %f s", cpu_time_used);
    printf("\n");

    free(emp);

}
