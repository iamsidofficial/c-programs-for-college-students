
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    unsigned dec,t,d,i;
    char bin[20],oct[15],hex[5];
    printf("Enter a decimal number : ");
    scanf("%u",&dec);
    t=dec;
    i=0;
    do
    {
        d=t%2;
        t=t/2;
        bin[i++]=d+48;
    }while(t!=0);
    bin[i]='\0';
    strrev(bin);
    t=dec;
    i=0;
    do
    {
        d=t%8;
        t=t/8;
        oct[i++]=d+48;
    }while(t!=0);
    oct[i]='\0';
    strrev(oct);
    t=dec;
    i=0;
    do
    {
        d=t%16;
        t=t/16;
        if(d>9) hex[i++]=d+55;
        else hex[i++]=d+48;
    }while(t!=0);
    hex[i]='\0';
    strrev(hex);
    printf("\nBinary equivalent of %u is %s",dec,bin);
    printf("\nOctal equivalent of %u is %s",dec,oct);
    printf("\nHexadecimal equivalent of %u is %s",dec,hex);
}
