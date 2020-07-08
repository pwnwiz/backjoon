// https://www.acmicpc.net/problem/14889
// 스타트와 링크
// Written in C++ langs
// 2020. 07. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MAP[20][20];
int N;

int RES = 9999999;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    vector<int> combination(N);
    for(int i=N/2; i<combination.size(); i++){
        combination[i] = 1;
    }
    
    do{
        vector<int> comb_A;
        vector<int> comb_B;
        
        for(int i=0; i<combination.size(); i++){
            if(combination.at(i) == 0){
                comb_A.push_back(i);
            } else {
                comb_B.push_back(i);
            }
        }

        int res_A = 0;
        for(int a=0; a<comb_A.size(); a++){
            for(int b=0; b<comb_A.size(); b++){
                res_A += MAP[comb_A[a]][comb_A[b]];
            }
        }
        
        int res_B = 0;
        for(int a=0; a<comb_B.size(); a++){
            for(int b=0; b<comb_B.size(); b++){
                res_B += MAP[comb_B[a]][comb_B[b]];
            }
        }
        
        RES = min(RES,abs(res_A - res_B));

    } while(next_permutation(combination.begin(), combination.end()));
    
    cout << RES << "\n";
    
    return 0;
    
}

