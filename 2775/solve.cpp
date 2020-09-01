// https://www.acmicpc.net/problem/2775
// 부녀회장이 될테야
// Written in C++ langs
// 2020. 09. 01.
// Wizley

#include <algorithm>
#include <iostream>

using namespace std;

int T;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    int k, n;
    while(T--){
        cin >> k >> n;
        int apart[15][15] = {0,};
        
        for(int i=1; i<=n; i++){
            apart[0][i] = i;
        }
        
        for(int j=1; j<=k; j++){
            for(int i=1; i<=n; i++){
                int people = 0;
                for(int q=1; q<=i; q++){
                    people += apart[j-1][q];
                }
                apart[j][i] = people;
            }
        }
        cout << apart[k][n] << "\n";
    }
  
    return 0;
    
}

