// https://www.acmicpc.net/problem/9251
// LCS
// Written in C++ langs
// 2020. 07. 09.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int LCS[1001][1001];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string A;
    string B;
    
    cin >> A;
    cin >> B;
             
    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            if(A[i-1] == B[j-1]){
                LCS[i][j] = LCS[i-1][j-1]+1;
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    
    cout << LCS[A.size()][B.size()] << "\n";
    
    return 0;
}

