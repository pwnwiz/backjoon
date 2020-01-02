// https://www.acmicpc.net/problem/11720
// 숫자의 합
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;
string INPUT;

int main(){
    int input;
    int val;
    int total = 0;
    cin >> input;
    
    for(int i=0; i<input; i++){
        scanf("%1d", &val);
        total += val;
    }
    
    cout << total << endl;
}

