// https://www.acmicpc.net/problem/1544
// 사이클 단어
// Written in C++ langs
// 2020. 08. 18.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    vector<string> input(N);
    vector<bool> checked(N, false);
    
    for(int i=0; i<N; i++){
        cin >> input[i];
    }
    
    int total = 0;
    for(int i=0; i<input.size(); i++){
        if(checked[i]) continue;
        
        total++;
        
        for(int j=0; j<input.size(); j++){
            
            if(input[i].length() != input[j].length()) continue;
            if(i == j || checked[j]) continue;

            for(int k=0; k<input[j].size(); k++){
                if(input[j][k] == input[i][0]){
                    int pos = k;
                    
                    bool flag = true;
                    for(int v = 0; v<input[j].size(); v++){
                        if(pos == input[j].size()) pos = 0;
                        
                        if(input[j][pos] != input[i][v]){
                            flag = false;
                            break;
                        }
                        
                        pos++;
                    }
                    
                    if(flag){
                        checked[j] = true;
                    }
                }
            }
            
        }
        
        checked[i] = true;
        
    }
    
    cout << total << "\n";
    
    return 0;
}

