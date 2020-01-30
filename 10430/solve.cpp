// https://www.acmicpc.net/problem/10430
// 나머지
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    
    cout << (A+B)%C << "\n";
    cout << (A%C + B%C)%C << "\n";
    cout << (A*B)%C << "\n";
    cout << (A%C * B%C)%C << "\n";
    
    return 0;
}

