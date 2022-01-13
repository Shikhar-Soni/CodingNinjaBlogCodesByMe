#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isPrime(int x){
    // there are better alternatives
    // and improvements possible
    // like rabin miller test or skipping check over even elements, etc
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void LargestSubsetWithCompositeSum(vector<int> a, int n){
    // sum of the elements in the vector
    int sum_of_elements = 0;
    for(int i = 0; i < n; i++){
        sum_of_elements += a[i];
    }
    
    //edge case when sum <= 2
    if(sum_of_elements <= 2){
        cout << -1 << endl;
        return;
    }
    if(isPrime(sum_of_elements)){
        // remove one odd element and print
        // print all elements except one odd element
        if(n == 1){
            cout << -1 << endl;
            return;
        }
        bool odd_found = -1;
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 1){
                odd_found = i;
                break;
            }
        }
        // if the sum is a prime number then it must have an odd number
        assert(odd_found != -1);
        
        if(sum_of_elements - a[odd_found] == 2){
            // special case when there's one odd and 2 in the array
            
            // if the odd number is not prime then we print it
            if(!isPrime(a[odd_found])){
                cout << 1 << endl;
                cout << a[odd_found] << endl;
            }
            else{
                cout << -1 << endl;
            }
            return;
        }
        
        cout << n - 1 << endl;
        
        // print all elements except the one at index odd_found
        for(int i = 0; i < odd_found; i++){
            cout << a[i] << " ";
        }
        for(int i = odd_found + 1; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else{
        //print all elements
        cout << n << endl;
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int32_t main(){
    // change input here
    vector<int> a = {7, 3, 1, 8, 4, 9, 5};
    int n = a.size();
    LargestSubsetWithCompositeSum(a, n);
}
