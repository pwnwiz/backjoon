// https://www.acmicpc.net/problem/10952
// A+B - 5
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <queue>

using namespace std;
int main(){
    int A, B;

    while(true){
        cin >> A >> B;
        if(A==0 && B==0) break;
        cout << A+B << endl;
    }
}
