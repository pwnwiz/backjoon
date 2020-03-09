// https://www.acmicpc.net/problem/1783
// 병든 나이트
// Written in C++ langs
// 2020. 03. 09.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int COUNT = 1;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int cur_N = 1;
    int cur_M = 1;
    if(N>2){
        if(M >= 5){
            cur_N += 1;
            cur_M += 2;
            COUNT += 1;
        
            if(M - cur_M > 2){
                cur_N -= 1;
                cur_M += 2;
                COUNT += 1;
            }

            int flag = 0;
            while(cur_M + 1<= M){
                if(flag == 0){
                    cur_N += 2;
                    cur_M += 1;
                    flag = 1;
                    COUNT += 1;
                }
                
                else if(flag == 1){
                    cur_N -= 2;
                    cur_M += 1;
                    flag = 0;
                    COUNT += 1;
                }
            }
                
        }
        
        else {
            int flag = 0;
            while(cur_M+1 <= M){
                if(flag == 0){
                    cur_N += 2;
                    cur_M += 1;
                    COUNT += 1;
                    flag = 1;
                }
                else if(flag == 1){
                    cur_N -= 2;
                    cur_M += 1;
                    COUNT += 1;
                    flag = 0;
                }
            }
        }
    }
    else if(N <= 1 || M<=1){
        
    }
    
    else{
        int flag = 0;
        while(cur_M + 2<= M){
            if(flag == 0){
                cur_N += 1;
                cur_M += 2;
                flag = 1;
                COUNT += 1;
            }
            
            else if(flag == 1){
                cur_N -= 1;
                cur_M += 2;
                flag = 0;
                COUNT += 1;
            }
            
            if(COUNT == 4)
                break;
        }
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

