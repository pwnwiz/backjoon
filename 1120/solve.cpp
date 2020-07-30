// https://www.acmicpc.net/problem/1120
// 문자열
// Written in C++ langs
// 2020. 07. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string A, B;
int RESULT = 987654321;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B;
    
    auto diff = B.length() - A.length();
    
    for(int i=0; i<=diff; i++){
        int cnt = 0;
        for(int j=0; j<A.length(); j++){
            if(A[j] != B[i+j]) cnt++;
        }
        
        RESULT = min(RESULT, cnt);
    }
    
    cout << RESULT << "\n";
    
    return 0;
}

