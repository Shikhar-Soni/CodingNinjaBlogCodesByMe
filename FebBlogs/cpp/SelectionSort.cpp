#include <bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int mn = i;
        for(int j = i + 1; j < n; j++){
            if(a[mn] > a[j]){
                mn = j;
            }
        }
        swap(a[mn], a[i]);
    }
}

void print_arr(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int32_t main(){
    int a[] = {5, 4, 3, 2, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Unsorted Array\n";
    print_arr(a, n);
    selection_sort(a, n);
    cout << "Sorted Array\n";
    print_arr(a, n);
}