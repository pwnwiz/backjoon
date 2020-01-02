// https://www.acmicpc.net/problem/2739
// 구구단
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    cin >> input;
    
    for(int i=1; i<=9; i++){
        cout << input << " * " << i << " = " << i*input << endl;
    }
    
}

