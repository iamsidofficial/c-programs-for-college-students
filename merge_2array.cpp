
/*
cpp program for merging two arraay
Author: Anil Kumar
Date modified:22-10-2021
*/


#include <iostream>
using namespace std;

void marge(int a[], int b[], int n1, int n2)
{

    int m[n1 + n2];

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            m[k] = a[i];
            i++;
            k++;
        }
        else
        {

            m[k] = b[j];
            j++;
            k++;
        }
    }

    if (i == n1)
    {

        do
        {
            m[k] = b[j];
            j++;
            k++;

        } while (j < n2);
    }
    if (j == n2)
    {

        do
        {
            m[k] = a[i];
            i++;
            k++;

        } while (i < n1);
    }

    for (int i = 0; i < n1+n2; i++)
    {
        cout<<m[i]<<" ";
    }
    
}

int main()
{

    cout << "number of element in 1 array:";
    int n1;
    cin >> n1;
    int a1[n1];
    cout << endl
         << "enter the elements:";
    for (int i = 0; i < n1; i++)
    {
        cin >> a1[i];
    }

    cout << endl
         << "enter the element in 2 array:";
    int n2;

    cin >> n2;
    int a2[n2];
    cout << "enter the elements:";
    for (int i = 0; i < n2; i++)
    {
        cin >> a2[i];
    }

    marge(a1, a2, n1, n2);
}
