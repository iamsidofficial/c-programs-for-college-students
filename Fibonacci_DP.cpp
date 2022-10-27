#include <iostream>
#define ll long long

using namespace std;

ll f (ll n) {
    
    ll dp[n];
    
    for (ll i = 0; i <= n; ++i) {
        dp[i] = -1;
    }
    
    if (n < 2) {
        return n;
    }
    
    if (dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = f (n - 1) + f (n - 2);
}

int main () {
    
    ll n = 3;
    
    ll dp[n];
    
    for (ll i = 0; i <= n; ++i) {
        dp[i] = -1;
    }
    
    cout << f (n);
    return 0;
}
