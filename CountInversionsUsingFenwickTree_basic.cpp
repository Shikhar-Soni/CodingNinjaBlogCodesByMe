#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

// required functions for fenwick tree, learn more about how these work through the shared links
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
    int mx = *max_element(a.begin(), a.end());
    vector<int> BIT(mx + 2, 0);
    int inv_count = 0;
    for(int i = 0; i < 5; i++){
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
    vector<int> a = {6, 4, 3, 2, 1};
    int n = a.size();
    cout << CountInversions(a, n) << endl;
}
