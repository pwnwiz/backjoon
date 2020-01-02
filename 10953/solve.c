// https://www.acmicpc.net/problem/10953
// A+B - 6
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>

using namespace std;
int main(){
    int count;
    int A, B;
    char comma;

    cin >> count;
    
    for(int i=0; i<count ;i++){
        cin >> A >> comma >> B;
        cout << A+B << endl;
    }
}

