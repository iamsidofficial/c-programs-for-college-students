
/*
cpp program for insertion sort
Author: Anil Kumar
Date modified:22-10-2021
*/
#include<iostream>
using namespace std;

void insertionshort(int a[],int n){

    for (int i = 1; i < n; i++)
    {
        int j=i-1;
        int x=a[i];
        while (j>=0 && a[j]>x)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
        

    }
    
}

int main(){

cout<<"enter the number of element:";
int n;
cin>>n;
int a[n];
cout<<endl<<"enter the the elements:";
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}

insertionshort(a , n);
cout<<endl<<"shorted elements:";
for (int i = 0; i < n; i++)
{
    cout<<a[i]<<" ";
}



}
