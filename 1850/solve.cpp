// https://www.acmicpc.net/problem/1850
// 최대공약수
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long gcd(long long A, long long B){
    long long C;
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
    long long A, B;
    cin >> A >> B;

    for(int i=0; i<gcd(A,B); i++){
        cout << '1';
    }
    cout << "\n";
    return 0;
}

