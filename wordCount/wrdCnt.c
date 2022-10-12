#include<stdio.h>
#include<conio.h>

void main()
{
	char str[80],c;
	int i,count=0,in=0;
	clrscr();
	printf("Enter a sentence : ");
	gets(str);
	for(i=0;(c=str[i])!='\0';i++)
	{
		if(c<'A' || c>'Z'&&c<'a' || c>'z') in=0;
		else if(!in)
		{
			in=1;
			count++;
		}
	}
	printf("\nNumber of words = %d",count);
	getch();
}
