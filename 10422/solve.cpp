// https://www.acmicpc.net/problem/10422
// 괄호
// Written in C++ langs
// 2020. 10. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

long long DP[5001];
int T;

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    int input;
    
    // ()
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 1;
    
    for(int i=3; i<=5000; i++){
        for(int j=2; j<=i; j++){
            if(i-j<0) continue;
  
            // ( xxxxxxx )( yyyyyyy )
            // ( xxxxxxx ) => 맨 처음과 끝 괄호를 빼면 j-2개를 가지게 됨
            // ( yyyyyyy ) 의 길이는 ( xxxxxxx ) 의 길이를 뺀 값임으로 i-j
            DP[i] += DP[j-2]*DP[i-j];
            DP[i] %= 1000000007;
        }
    }
    DP[0] = 0;
    
    for(int i=0; i<T; i++){
        cin >> input;
        cout << DP[input] << "\n";
    }
    
    
}

