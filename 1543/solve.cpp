// https://www.acmicpc.net/problem/1543
// 문서 검색
// Written in C++ langs
// 2020. 08. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string A, B;
int CNT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, A);
    getline(cin, B);

    while(true){
        auto n = A.find(B);
        
        if(n == string::npos){
            break;
        }
        CNT++;
        A.erase(A.begin(), A.begin()+n+B.size());
    }
    
    cout << CNT << "\n";
    
    return 0;
}

