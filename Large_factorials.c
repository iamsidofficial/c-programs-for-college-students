#include<stdio.h>
#include<string.h>

#define MAX 600

int res[MAX];
int multi(int a[],int,int);


int main(int argc, char const *argv[])
{
	int n,size=1;
	res[0]=1;
	scanf("%d",&n);
    for (int i = 2; i <=n ; ++i)
    {
    	size = multi(res,i,size);
    }
    for (int i = size-1; i >=0; --i)
    {
    	printf("%d",res[i] );
    }
    printf("\n");
	return 0;
}


int multi(int a[],int x,int size)
{
	int carry=0,product;
	for (int i = 0; i <size; ++i)
	{
		product = a[i] * x + carry;
		a[i] = product%10;
		carry = product/10;
	}
	while(carry)
	{
		res[size] = carry%10;
		carry = carry/10;
		size++;
	}
	return size;
}
