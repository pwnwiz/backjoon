// https://www.acmicpc.net/problem/11718
// 그대로 출력하기
// Written in C++ langs
// 2020. 01. 02.
// Wizley

#include <iostream>
#include <string>

using namespace std;
string INPUT;

int main(){
    while(true){
        getline(cin, INPUT);
        if(cin.eof()) break;
        cout << INPUT << endl;
    }
}

