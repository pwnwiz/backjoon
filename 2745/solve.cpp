// https://www.acmicpc.net/problem/2745
// 진법 변환
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A;
    int B, C=0;
    cin >> A >> B;

    int digit=1;
    for(auto i=A.rbegin(); i<A.rend(); i++){
        if(*i>='0' && *i<='9'){
            C += digit * (*i-'0');
        } else{
            C += digit * ((*i+10)-'A');
        }
        digit *= B;
    }
    
    cout << C <<"\n";
    return 0;
}

