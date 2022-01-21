#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string remove_zeros_from_front(string a){
    for(int i = 0; i < a.size(); i++){
        // if the digit isn't '0' then all of the numbers after it are returned
        if(a[i] != '0')
            return a.substr(i, a.size() - i);
    }
    // if all the digits were '0' or empty we return "0"
    return "0";
}

string str_add(string a, string b){
    if(a.size() > b.size()) swap(a, b);
    
    int n = a.size();
    int diff = b.size() - a.size();
    string ans;
    int carry = 0;
    for(int i = n-1; i > -1; i--){
        // calculate sum of digits and carry
        int sum_d = (a[i] - '0') + (b[i + diff] - '0') + carry;
        carry = sum_d / 10;
        ans.push_back(sum_d % 10 + '0');
    }
    for(int i = diff - 1; i > -1; i--){
        // calculate sum of extra digits and carry
        int sum_d = (b[i] - '0') + carry;
        carry = sum_d / 10;
        ans.push_back(sum_d % 10 + '0');
    }
    // if there is still a carry then put carry in the answer
    if(carry){
        ans.push_back(carry + '0');
    }
    //reverse to get the answer in the correct order and return
    reverse(ans.begin(), ans.end());
    return ans;
}

string str_sub(string b, string a){
    if(a.size() > b.size()) swap(a, b);
    
    int n = a.size();
    int diff = b.size() - a.size();
    string ans;
    int carry = 0;
    for(int i = n-1; i > -1; i--){
        // subtract digits and carry
        int diff_d = (b[i + diff] - '0') - (a[i] - '0') - carry;
        // if digit difference was negative, set carry to 1
        carry = (diff_d < 0);
        // if digit difference is negative then add 10 to make it non-negative
        diff_d += 10 * carry;
        ans.push_back(diff_d + '0');
    }
    for(int i = diff - 1; i > -1; i--){
        // calculate difffernce of extra digits and carry
        int diff_d = (b[i] - '0') - carry;
        carry = (diff_d < 0);
        diff_d += 10 * carry;
        ans.push_back(diff_d + '0');
    }
    // b > a is the assumption
    assert(carry == 0);
    //reverse to get the answer in the correct order and return
    reverse(ans.begin(), ans.end());
    return ans;
}

string single_dig_mul(string b, char a){
    string ans;
    int d = a - '0', carry = 0;
    for(int i = b.size() - 1; i > -1; i--){
        // multiply all digits with the signle digit d
        int mul_d = (b[i] - '0') * d + carry;
        carry = mul_d / 10;
        ans.push_back(mul_d % 10 + '0');
    }
    // if carry still there then add that to the answer
    if(carry) ans.push_back(carry + '0');
    //reverse to get the answer in the correct order and return
    reverse(ans.begin(), ans.end());
    return ans;
}

string karatsuba(string a, string b){
    // ensure that a is less than equal to b in size
    if(a.size() > b.size()) swap(a, b);
    
    //a is smaller than equal to b
    int A = a.size(), B = b.size();
    if(A == 1) return single_dig_mul(b, a[0]);
    
    string copy_A, copy_B;
    if(B&1){
        // making B have even length by adding '0' in the front
        copy_B.push_back('0');
        B += 1;
    }
    for(int i = 0; i < B - A; i++){
        // adding '0' in front of string a to make both the strings have equal length
        copy_A.push_back('0');
    }
    // both the string copy_A and copy_B are of the same size
    copy_A = copy_A + a;
    copy_B = copy_B + b;
    
    // split string copy_A and copy_B into equal parts, namely
    // A_l and A_r for A and
    // B_l and B_r for B
    string A_l, A_r, B_l, B_r;
    A_l = copy_A.substr(0, B/2);
    A_r = copy_A.substr(B/2, B/2);
    B_l = copy_B.substr(0, B/2);
    B_r = copy_B.substr(B/2, B/2);
    
    /*
    => A * B
    => (Al * 10^(n/2) + Ar) * (Bl * 10^(n/2) + Br)
    => (Al*Bl*10^(n) + (Al*Br + Ar*Bl) * 10^(n/2) + Ar*Br)
    => (Al*Bl*10^(n) + ((Al+Ar)*(Bl+Br)-Al*Bl-Ar*Br)*10^(n/2) + Ar*Br)
    */
    
    // Al * Bl
    string I_1 = karatsuba(A_l, B_l);
    // Ar * Br
    string I_2 = karatsuba(A_r, B_r);
    // (Al + Ar) * (Bl + Br)
    string I_3 = karatsuba(str_add(A_l, A_r), str_add(B_l, B_r));
    // Al * Bl + Ar * Br
    string sum_I1_I2 = str_add(I_1, I_2);
    // (Al + Ar) * (Bl + Br) - (Al * Bl + Ar * Br)
    // (Al + Ar) * (Bl + Br) - Al * Bl - Ar * Br
    I_3 = str_sub(I_3, sum_I1_I2);
    // Al * Bl * 10^(n)
    I_1 += string(B, '0');
    // ((Al + Ar) * (Bl + Br) - Al * Bl - Ar * Br) * 10^(n/2)
    I_3 += string(B/2, '0');
    // (Al*Bl*10^(n) + ((Al+Ar)*(Bl+Br)-Al*Bl-Ar*Br)*10^(n/2) + Ar*Br)
    string I_4 = str_add(I_3, str_add(I_1, I_2));
    
    // return extra zeros from the front and return result
    return remove_zeros_from_front(I_4);
}

int32_t main(){
    // change input to any number by changing string 'a' and 'b' here
    string a = "907843";
    string b = "578934";
    string ans = karatsuba(a, b);
    cout << ans << endl;
}
