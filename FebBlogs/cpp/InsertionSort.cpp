#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int unsorted_element = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > unsorted_element){
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = unsorted_element;
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
    insertion_sort(a, n);
    cout << "Sorted Array\n";
    print_arr(a, n);
}