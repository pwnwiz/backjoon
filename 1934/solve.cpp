// https://www.acmicpc.net/problem/1934
// 최소공배수
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
    int count;
    cin >> count;
    
    for(int i=0; i<count; i++){
        int A, B;
        cin >> A >> B;

        cout << lcm(A,B) << "\n";
    }
    return 0;
}

