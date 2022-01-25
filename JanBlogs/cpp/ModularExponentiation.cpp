#include <bits/stdc++.h>
using namespace std;

// uncomment if needed
// #define int long long

int modular_exponentiation(int a, int b, int MOD = 1e9 + 7){
    int ans = 1;
    a = a % MOD;
    while(b > 0){
        if(b % 2 == 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b / 2;
    }
    return ans;
}

int32_t main(){
    int a = 2, b = 10, MOD = 499;
    cout << modular_exponentiation(a, b, MOD);
}
