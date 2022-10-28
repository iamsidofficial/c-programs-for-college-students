#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};


int main(){
  struct stack q;
  q.size=10;
  q.s=(int*)malloc(sizeof(int)*q.size);
  q.top=-1;  



return 0;

}