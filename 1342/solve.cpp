// https://www.acmicpc.net/problem/1342
// 행운의 문자열
// Written in C++ langs
// 2020. 08. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string S;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S;

    sort(S.begin(), S.end());
    
    int result = 0;
    do {
        bool flag = true;
        for(int i=0; i<S.size()-1; i++){
            if(S[i]==S[i+1]){
                flag = false;
                break;
            }
        }
        if(flag){
            result++;
        }
    } while(next_permutation(S.begin(), S.end()));
    
    cout << result << "\n";
    return 0;
}

