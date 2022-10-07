// In this sort , we sort the array in the form of wave in which the every alternate array is less than its before element and after elements

#include <iostream>
using namespace std;

void wavesort(int arr[], int n)
{
    for (int i = 1; i < n;)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr[i], arr[i - 1]);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr[i], arr[i + 1]);
        }
        i += 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    wavesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}