// https://www.acmicpc.net/problem/11655
// ROT13
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string ROT13(string str){
    for(int i=0; i<str.size(); i++){
        if((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm')){
            str[i] = str[i] + 13;
        } else if((str[i] >='N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z')){
            str[i] = str[i] - 13;
        }
    }
    return str;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    getline(cin, S);

    cout << ROT13(S) << "\n";
}

