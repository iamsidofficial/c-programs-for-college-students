#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int divide(int *a,int start,int end)
{
	int i=start+1,j,t;
	int div=a[start];
	for(j=start+1;j<=end;j++)
	{
		if(a[j]<div)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
		}
	}
	t=a[i-1];
	a[i-1]=a[start];
	a[start]=t;
	return (i-1);		
}
void quicksort(int *a,int start,int end)
{
	int pos;
	if(start<end)
	{
		pos=divide(a,start,end);
		quicksort(a,start,pos-1);
		quicksort(a,pos+1,end);
	}
}
long best(int n)
{
	int i;
	struct timeval start,end;
	long time;
	int *a=(int *) malloc (n*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=i;
	}
	gettimeofday(&start,NULL);
	quicksort(a,0,n-1);
	gettimeofday(&end,NULL);
	time=end.tv_sec-start.tv_sec;
	time=time*1000000+end.tv_usec-start.tv_usec;
	return time;
}
long avg(int n)
{
	int i;
	struct timeval start,end;
	long time;
	int *a=(int *) malloc (n*sizeof(int));
	for(i=0;i<n;i++)
		a[i]=rand();
	gettimeofday(&start,NULL);
	quicksort(a,0,n-1);
	gettimeofday(&end,NULL);
	time=end.tv_sec-start.tv_sec;
	time=time*1000000+end.tv_usec-start.tv_usec;
	return time;
}
long worst(int n)
{
	int i,base=111111;
	struct timeval start,end;
	long time;
	int *a=(int *) malloc (n*sizeof(int));
	for(i=0;i<n;i++)
	{
		a[i]=base;
		base--;
	}
	gettimeofday(&start,NULL);
	quicksort(a,0,n-1);
	gettimeofday(&end,NULL);
	time=end.tv_sec-start.tv_sec;
	time=time*1000000+end.tv_usec-start.tv_usec;
	return time;
}
void main()
{
	int i,j,n;
	long a[3][3];
	a[0][0]=best(1000);
	a[0][1]=avg(1000);
	a[0][2]=worst(1000);
	a[1][0]=best(10000);
	a[1][1]=avg(10000);
	a[1][2]=worst(10000);
	a[2][0]=best(100000);
	a[2][1]=avg(100000);
	a[2][2]=worst(100000);
	printf("\tBest Case\tAverage Case\tWorst Case\n");
	for(i=0;i<3;i++)
	{
		if(i==0)
			printf("1000");
		if(i==1)
			printf("10000");
		if(i==2)
			printf("100000");
		for(j=0;j<3;j++)
		{
			if(a[i][j]>=10000000)
				printf("\t%ld",a[i][j]);
			else
				printf("\t%ld\t",a[i][j]);
		}
		printf("\n");
	}
}
