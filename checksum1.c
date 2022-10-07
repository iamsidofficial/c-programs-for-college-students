//CHECKSUM
#include<stdio.h>

#include<conio.h>

#include<math.h>

int sender(int b[10],int k)

{

	int checksum,sum=0,i;

	printf("\n***SENDER*\n");

for(i=0;i<k;i++)

		sum+=b[i];

		printf("SUM IS: %d",sum);

	checksum=~sum;

	printf("\nSENDER's CHECKSUM IS:%d",checksum);

	return checksum;

}

int receiver(int c[10],int k,int scheck)

{

int checksum,sum=0,i;

	printf("\n\n***RECEIVER*\n");

	for(i=0;i<k;i++)

		sum+=c[i];

	printf(" RECEIVER SUM IS:%d",sum);

	sum=sum+scheck;

	checksum=~sum;

	printf("\nRECEIVER's CHECKSUM IS:%d",checksum);

		return checksum;

}

main()

{

	int a[10],i,m,scheck,rcheck;

	printf("\nENTER SIZE OF THE STRING:");

	scanf("%d",&m);

	printf("\nENTER THE ELEMENTS OF THE ARRAY:");

	for(i=0;i<m;i++)

	scanf("%d",&a[i]);

	scheck=sender(a,m);

	rcheck=receiver(a,m,scheck);

	if(rcheck==0)

		printf("\n\nNO ERROR IN TRANSMISSION\n\n");

	else

		printf("\n\nERROR DETECTED");

getch();

}
