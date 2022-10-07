#include <iostream>  
#include <conio.h>  
using namespace std;  
int main ()  
{  
    int arr[100], st, mid, end, i, num, tgt;  
      
    cout << " Define the size of the array: " << endl;  
    cin >> num;  
      
        cout << " Enter the values in sorted array either ascending or descending order: " << endl;  
    for (i = 0; i < num; i++)  
    {  
        cout << " arr [" << i << "] = ";  
        cin >> arr[i];  
    }  
      
    st = 0;  
    end = num - 1; 
      
    cout << " Define a value to be searched from sorted array: " << endl;  
    cin >> tgt;  
      
    while ( st <= end)  
    {  
        mid = ( st + end ) / 2;  
        if (arr[mid] == tgt)  
        {  
            cout << " Element is found at index " << (mid + 1);  
            exit (0); 
        }  
        else if ( tgt > arr[mid])  
        {  
            st = mid + 1;   
        }  
          
        else if ( tgt < arr[mid])  
        {  
            end = mid - 1;   
        }  
    }  
    cout << " Number is not found. " << endl;  
    return 0;  
}   