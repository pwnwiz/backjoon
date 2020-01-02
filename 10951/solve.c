// https://www.acmicpc.net/problem/10951
// A+B - 4
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
        if(cin.eof() == true) break;
        cout << A+B << endl;
    }
}

