#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
   return (a > b)? a : b;
}
int max(int a, int b, int c) {
   return max(max(a, b), c);
}
int getMaxCrossingSum(int arr[], int l, int m, int h) {
   int sum = 0;
   int left = INT_MIN;
   for (int i = m; i >= l; i--) {
      sum = sum + arr[i];
      if (sum > left)
         left = sum;
   }
   sum = 0;
   int right = INT_MIN;
   for (int i = m+1; i <= h; i++) {
      sum = sum + arr[i];
      if (sum > right)
      right = sum;
   }
   return left + right;
}
int maxSubArraySum(int arr[], int low, int high) {
   if (low == high)
   return arr[low];
   int mid = (low + high)/2;
   return max(maxSubArraySum(arr, low, mid), maxSubArraySum(arr, mid+1, high), getMaxCrossingSum(arr, low, mid, high));
}
int main() {
   int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
   int n = sizeof(arr)/sizeof(arr[0]);
   int max_sum = maxSubArraySum(arr, 0, n-1);
   printf("Maximum contiguous sum is %d", max_sum);
}
