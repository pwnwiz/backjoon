// https://www.acmicpc.net/problem/11021
// A+B - 7
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>

using namespace std;
int main(){
    int count;
    int A, B;

    cin >> count;
    
    for(int i=0; i<count ;i++){
        cin >> A >> B;
        cout << "Case #" << i+1 << ": " << A+B << endl;
    }
}

