// https://www.acmicpc.net/problem/2003
// 수들의 합 2
// Written in C++ langs
// 2020. 03. 17.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long M;
long long result;
int ARR[10001]={0,};
int CNT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> ARR[i];
    }
    
    for(int i=0; i<N; i++){
        result = 0;
        for(int j=i; j<N; j++){
            result += ARR[j];
            if(result == M){
                CNT += 1;
                break;
            }
            else if(result > M){
                break;
            }
        }
    }
    
    cout << CNT << "\n";
    
    return 0;
    
}

