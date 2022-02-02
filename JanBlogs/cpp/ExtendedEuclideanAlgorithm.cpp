#include <bits/stdc++.h>
using namespace std;

// uncomment if needed
// #define int long long

int extended_euclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        // if b is 0, return
        x = 1, y = 1000;
        return a;
    }
    int x1, y1;
    int d = extended_euclidean(b, a % b, x1, y1);
    y = x1 - (a / b) * y1;
    x = y1;
    return d;
}

int32_t main(){
    int a = 2, b = 32;
    int x, y;
    cout << "gcd = " << extended_euclidean(a, b, x, y) << endl;
    cout << "x = " << x << ", y = " << y << endl;
}