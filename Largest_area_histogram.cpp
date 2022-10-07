// C++ program to find maximum rectangular area in

#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n)
{
    stack<int> s;
 
    int max_area = 0; // Initialize max area
    int top; 
    int small_area; 
                       
    int i = 0;
    while (i < n) {
        
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        
        else {
            top = s.top(); // store the top index
            s.pop(); // pop the top
 
            
            small_area
                = hist[top]
                  * (s.empty() ? i : i - s.top() - 1);
 
            
            if (max_area < small_area)
                max_area = small_area;
        }
    }
 
    while (s.empty() == false) {
        top = s.top();
        s.pop();
        small_area
            = hist[top] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < small_area)
            max_area = small_area;
    }
 
    return max_area;
}
 
int main()
{
    int hist[] = { 6, 2, 5, 4, 5, 1, 6 };
    int n = sizeof(hist) / sizeof(hist[0]);
 
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
