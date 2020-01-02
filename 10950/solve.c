// https://www.acmicpc.net/problem/10950
// A+B - 3
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <queue>

using namespace std;
int main(){
    int count;
    int A, B;
    cin >> count;
    for(int i=0; i<count; i++){
        cin >> A >> B;
        cout << A+B << endl;
    }
}

