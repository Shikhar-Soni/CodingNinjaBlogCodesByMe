#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void add(vector<int>& BIT, int idx, int val){
    idx += 1;
    while(idx < BIT.size()){
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int query(vector<int>& BIT, int idx){
    idx += 1;
    int sum = 0;
    while(idx){
        sum += BIT[idx];
        idx &= idx - 1;
    }
    return sum;
} 

void CountInversions(vector<int> a, int n){
    vector<int> BIT(n+1, 0);
    for(int i = 0; i < n; i++){
        add(BIT, i, 5);
    }
    cout << query(BIT, n-1) << endl;
    add(BIT, 0, -1);
    cout << query(BIT, n-1) << endl;
}

int32_t main(){
    // change input here
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    CountInversions(a, n);
}
