#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int count_swaps = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                count_swaps += 1;
            }
        }
        if(!count_swaps) break;
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
    bubble_sort(a, n);
    cout << "Sorted Array\n";
    print_arr(a, n);
}