// https://www.acmicpc.net/problem/11005
// 진법 변환 2
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> RESULT;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B;
    cin >> A >> B;

    while(A){
        RESULT.push_back(A % B);
        A = A / B;
    }
    
    for(auto i= RESULT.rbegin(); i<RESULT.rend(); i++)
        *i>=10 ? cout << char('A'+(*i-10)) : cout << *i;
    
    cout <<"\n";
    return 0;
}

