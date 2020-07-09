// https://www.acmicpc.net/problem/9252
// LCS 2
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
    
    int lcs = LCS[A.size()][B.size()];
    cout << lcs << "\n";

    string result;
    int x = A.size();
    int y = B.size();

    
    while(LCS[x][y]){
        
        if(LCS[x][y] == LCS[x][y-1]){
            y--;
        }
        
        else if(LCS[x][y] == LCS[x-1][y]){
            x--;
        }
        
        else if(LCS[x][y] == LCS[x-1][y-1] + 1){
            x--;
            y--;
            result += B[y];
        }
    }
    
    reverse(result.begin(), result.end());
    cout << result << "\n";
    
    
    return 0;
}

