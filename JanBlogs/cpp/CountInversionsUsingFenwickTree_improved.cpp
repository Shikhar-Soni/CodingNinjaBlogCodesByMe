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

int CountInversions(vector<int> a, int n){
    vector<int> BIT(n + 1, 0);
    vector<int> b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    // now for all i, 0 <= a[i] < n
    int inv_count = 0;
    for(int i = 0; i < n; i++){
        // increasing index a[i] by 1
        add(BIT, a[i], 1);
        // count of numbers greater than a[i] before it
        // being added to the inverse count
        inv_count += i - query(BIT, a[i]) + 1;
    }
    return inv_count;
}

int32_t main(){
    // change input here
    vector<int> a = {2, 1, 2, 5, 999999, 3};
    int n = a.size();
    cout << CountInversions(a, n) << endl;
}
