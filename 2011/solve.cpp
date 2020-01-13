// https://www.acmicpc.net/problem/2011
// 암호코드
// Written in C++ langs
// 2020. 01. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string input;

long long DP[5001]={0,};

int isTwoDigit(int number){
    return (number >= 1 && number <=26);
}

int isDigit(int number){
    return (number >= 1 && number <=9);
}

int main() {
    
    cin >> input;
    input = " " + input;
    
    DP[0] = 1;
    
    for(int i=1; i<input.length(); i++){
        if(isDigit(input[i]-'0')){
            DP[i] += DP[i-1];
            DP[i] %= 1000000;
        }
        
        if(i == 1) continue;
        if(input[i-1] == '0') continue;
        
        if(isTwoDigit((input[i-1]-'0')*10 + input[i]-'0')){
            DP[i] += DP[i-2];
            DP[i] %= 1000000;
        }
    }
    
    cout << DP[input.length()-1] << endl;
    return 0;
}

