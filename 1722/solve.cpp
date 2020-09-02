// https://www.acmicpc.net/problem/1722
// 순열의 순서
// Written in C++ langs
// 2020. 09. 02.
// Wizley

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long FACTORIAL[21];
vector<bool> USED(21, false);
int N, K;

long long getFactorial(int n){
    if(n == 1) return FACTORIAL[1] = 1;
    return FACTORIAL[n] = n * getFactorial(n-1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    
    FACTORIAL[0] = 1;
    getFactorial(N);
    
    cin >> K;
    
    if(K == 1){
        long long idx;
        cin >> idx;
        
        vector<int> result;
        
        for(int pos=1; pos<=N; pos++){
            for(int cur_no=1; cur_no<=N; cur_no++){
                if(USED[cur_no]) continue;
                
                long long cur_idx = FACTORIAL[N-pos];
                
                if(idx > cur_idx) idx -= cur_idx;
                
                else {
                    USED[cur_no] = true;
                    result.push_back(cur_no);
                    break;
                }
            }
        }
        for(auto r : result){
            cout << r << " ";
        }
        cout << "\n";
    } else {
        vector<int> target(N);
        for(int i=0; i<N; i++){
            cin >> target[i];
        }
        
        long long idx = 0;
        for(int pos=0; pos<N; pos++){
            for(int cpos=1; cpos<target[pos]; cpos++){
                if(USED[cpos]) continue;
                
                idx += FACTORIAL[N-pos-1];
            }
            USED[target[pos]] = true;
        }
        cout << idx+1 << "\n";
    }
}

