#include <bits/stdc++.h>
using namespace std;

// uncomment if needed
// #define int long long

int extended_euclidean(int a, int b, int& x, int& y) {
    if (!a) {
        // if a is 0, return
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - x1 * (b / a);
    y = x1;
    return d;
}

int modular_multiplicative_inverse(int a, int m){
    int x, y;
    int gcd_a_and_m = extended_euclidean(a, m, x, y);
    
    // if the gcd is 1, the multiplicative modular inverse exists
    if(gcd_a_and_m == 1){
        // handle the case when x < 0
        x = (x % m + m) % m;
        return x;
    }
    return -1;
}

int32_t main(){
    int a = 10, MOD = 499;
    cout << modular_multiplicative_inverse(a, MOD);
}