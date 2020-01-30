// https://www.acmicpc.net/problem/2609
// 최대공약수와 최소공배수
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int gcd(int A, int B){
    int C;
    while(B!=0){
        C = A % B;
        A = B;
        B = C;
    }
    return A;
}

int lcm(int A, int B){
    return (A*B)/gcd(A,B);
}

int main(){
    int A, B;
    cin >> A >> B;
    
    cout << gcd(A,B) << "\n";
    cout << lcm(A,B) << "\n";
    
    return 0;
}

