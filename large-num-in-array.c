#include"stdio.h"
int main()
{
    int num[5],max;
    printf("Enter numbers\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &num[i]);
    }
    printf("You entered numbers!\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", num[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        while (max < num[i])
        {
            max = num[i];
        }
    }
    printf("Max number is %d\n", max);
}
