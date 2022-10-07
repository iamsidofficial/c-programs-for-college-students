#include <stdio.h>
#include <stdlib.h>

int getLongestSequence(long long int num){
    int binary[1001],binInd=0;
    while(num>0){
        binary[binInd++]=num%2;
        num/=2;
    }
    binary[binInd++]=1;
    int maxLen=-1001,currLen=0;
    for(int index=0;index<binInd;index++){
        if(binary[index]==0){
            currLen++;
        }
        else{
            if(currLen>maxLen){
                maxLen=currLen;
            }
            currLen=0;
        }
    }
    return maxLen;
}

int main()
{
    int N;
    scanf("%d",&N);
    long long int arr[N],maxLen=-1001;
    for(int index=0;index<N;index++){
        scanf("%lld",&arr[index]);
        int currLen=getLongestSequence(arr[index]);
        if(currLen>maxLen){
            maxLen=currLen;
        }
    }
    for(int index=N-1;index>=0;index--){
        if(getLongestSequence(arr[index])==maxLen){
            printf("%lld ",arr[index]);
        }
    }
    return 0;
}
