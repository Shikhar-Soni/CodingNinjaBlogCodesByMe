#include <bits/stdc++.h>
using namespace std;

// uncomment if needed
// #define int long long

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int iterative_gcd(int a, int b){
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int32_t main(){
    int a = 15, b = 33;
    cout << gcd(a, b) << endl;
    cout << iterative_gcd(a, b) << endl;
}