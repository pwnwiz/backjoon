// https://www.acmicpc.net/problem/10820
// 문자열 분석
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    
    while(getline(cin, S)){
            
        int res[4]={0,};
        
        for(int i=0; i<S.size(); i++){
            if(S[i] >= 'a' && S[i] <= 'z'){
                res[0]++;
            } else if(S[i] >= 'A' && S[i] <= 'Z'){
                res[1]++;
            } else if(S[i] >= '0' && S[i] <= '9'){
                res[2]++;
            } else if(S[i] == ' '){
                res[3]++;
            }
        }
        cout << res[0] << ' ' << res[1] << ' ' << res[2] << ' ' << res[3] << ' ' << "\n";
    }
    
}

