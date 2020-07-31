// https://www.acmicpc.net/problem/2503
// 숫자 야구
// Written in C++ langs
// 2020. 07. 31.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> N;
    
    vector<string> pool;
    for(int i=123; i<=987; i++){
        auto cur = to_string(i);
        if(cur[0] == cur[1] || cur[1] == cur[2] || cur[2] == cur[0]) continue;
        if(cur[0] == '0' || cur[1] == '0' || cur[2] == '0') continue;
        pool.push_back(cur);
    }
    
    char input[3];
    int strike;
    int ball;
    for(int i=0; i<N; i++){
        cin >> input;
        cin >> strike;
        cin >> ball;
        
        vector<string> tmp;
        
        for(auto idx: pool){
            int nstrike = 0;
            int nball = 0;
            
            for(int x=0; x<3; x++){
                if(idx[x] == input[x]) nstrike++;
                for(int y=0; y<3; y++){
                    if(x==y) continue;
                    if(idx[x] == input[y]) nball++;
                }
            }
            
            if(nstrike == strike && nball == ball){
                tmp.push_back(idx);
            }
        }
        
        pool = tmp;
    }
    
    cout << pool.size() << "\n";
    
    return 0;
    
}

