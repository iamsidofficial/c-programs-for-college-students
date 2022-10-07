#include<stdio.h>
#include<pthread.h>
#include<string.h>
int n;
void *fun1(void *args)
{
        pthread_t call_id=(pthread_t)args;
        printf("\ncaller id :%lu",call_id);
        pthread_t sid;
        printf("\n Thread id :%lu",sid);
        int i,f=1;
        for(i=1;i<=n;i++)
                f=f*i;
        printf("\n Factorial of %d is %d",n,f);
}
void *func2(void *args)
{
        int i,f=1,sum=0,j;
        pthread_t call_id=(pthread_t)args;
        printf("\ncaller id :%lu",call_id);
        pthread_t sid;
        printf("\n Thread id :%lu",sid);
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=i;j++)
                {
                        f=f*j;
                }
                sum=sum+f;
                f=1;
        }
        printf("\n Total Number of factorial of %d is %d\n",n,sum);
}
void main()
{
        printf("\n Enter the value of n : ");
        scanf("%d",&n);
        printf("\n Strating of thread 1");
        pthread_t t_id,sid;
        sid=pthread_self();
        pthread_create(&t_id,NULL,fun1,(void*)&sid);
        pthread_join(t_id,NULL);
        printf("\n Ending of thread 1");
        printf("\n Starting thread 2");
        pthread_t w_id,si;
        si=pthread_self();
        pthread_create(&w_id,NULL,func2,(void*)&si);
        pthread_join(w_id,NULL);
        printf("Ending of thread 2\n");

}