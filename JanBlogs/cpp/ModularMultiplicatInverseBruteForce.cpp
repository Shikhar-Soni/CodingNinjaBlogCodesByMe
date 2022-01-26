#include <bits/stdc++.h>
using namespace std;

// uncomment if needed
// #define int long long

int modular_multiplicative_inverse(int a, int MOD = 1e9 + 7){
    
    a = a % MOD;
    for(int i = 1; i <= MOD-1; i++){
        if((a * i) % MOD == 1){
            return i;
        }
    }
    return -1;
}

int32_t main(){
    int a = 10, MOD = 499;
    cout << modular_multiplicative_inverse(a, MOD);
}
