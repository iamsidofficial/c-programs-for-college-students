#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	printf("---------------------------------------------------\n");
	printf("Enter a number from which you want to count:\t");
	scanf("%d", &i);
	printf("\n---------------------------------------------------\n");

	for (i; i <= 100; i++)
	{

		printf("%d\n", i);
	}
	return 0;
}
