#include<iostream>
using namespace std;
int det(int**a,int n){
    
    if(n==1)  return a[0][0];
    int sum=0;
    for(int c=0;c<n;c++)  {
       int **b;  b=new int*[n-1];
       for(int i=0;i<n-1;i++)  b[i]=new int[n-1];
       for(int r=0;r<n-1;r++) 
       for(int q=0;q<n-1;q++)
        { 
            if(q<c)  b[r][q]=a[r+1][q];
            else b[r][q]=a[r+1][q+1];
        }
       
        
        if(c%2==0) sum+=a[0][c]*det(b,n-1);
        else sum+=-a[0][c]*det(b,n-1) ;
    }
    return sum;
}
int main(){
    int n; cin>>n;
    int**a; a=new int*[n];
    for(int i=0;i<n;i++)  a[i]=new int[n];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    cin>>a[i][j];

    cout<<"\nDeterminant is "<<det(a,n);
    
    return 0;
}