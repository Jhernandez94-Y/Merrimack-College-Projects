#include <iostream>
#include <string>
using namespace std;

void increment(string& binary) {
    int n = binary.length();
    bool carry = true;  
    for (int i = n - 1; i >= 0; i--) {
        if (binary[i] == '0' && carry) {
            binary[i] = '1';
            carry = false;  
            break;
        }
        else if (binary[i] == '1' && carry) {
            binary[i] = '0';
            carry = true;  
        }
    }
    if (carry) {
        binary = '1' + binary;
    }
}

void decrement(string& binary) {
    int n = binary.length();
    bool borrow = true; 
    for (int i = n - 1; i >= 0; i--) {
        if (binary[i] == '1' && borrow) {
            binary[i] = '0';
            borrow = false;
            break;
        }
        else if (binary[i] == '0' && borrow) {
            binary[i] = '1';
            borrow = true; 
        }
    }
    
    int zero = 0;
    while (zero < binary.length() && binary[zero] == '0') {
        zero++;
    }
    binary = binary.substr(zero);  
    if (binary.empty()) binary = "0";  
}

string addBinary(string a, string b) {
    int lenA = a.length();
    int lenB = b.length();
    int maxLen = (lenA > lenB) ? lenA : lenB;
    while (a.length() < maxLen) {
        a = '0' + a;
    }
    while (b.length() < maxLen) {
        b = '0' + b;
    }

    while (b != "0") {
        increment(a);  
        decrement(b);  
    }

    return a;
    }

int main() {
    string a, b;

    cout << "Enter the first binary number: ";
    cin >> a;
    cout << "Enter the second binary number: ";
    cin >> b;
    for (int e = 0; e < a.length(); e++){ 
        if (a[e] == '0' or a[e] == '1' or b[e] == '0' or b[e] == '1'){
            continue;
        }
        else{
            cout<<"Invalid values, try again!"<<endl;
            return 0;
        }
    }
    string result = addBinary(a, b);
    
    cout << "The sum of the binary numbers is: " << result << endl;
    return 0;
}