#include <stdio.h>
#include <stdlib.h>

int what(char A[],int lb, int ub){
    if(lb<ub){
        if(A[lb]!=A[ub]){
            return 0;
        }
        return what(A,++lb,--ub);
    }
    return -1;
}
int main(){
    char A[3]={'a','b','c'};
    what(A,0,2);
    



return 0;

}