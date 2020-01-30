// https://www.acmicpc.net/problem/1373
// 2진수 8진수
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
    cin >> A;
    
    if(A.size()%3 == 1) cout << A[0];
    else if(A.size()%3 == 2) cout << (A[0]-'0')*2 + (A[1]-'0');
    
    for(int i=A.size()%3; i<A.size(); i+=3){
        cout << (A[i]-'0')*2*2 + (A[i+1]-'0')*2 + (A[i+2]-'0');
    }
    
    cout << "\n";
    return 0;
}

