// https://www.acmicpc.net/problem/6603
// 로또
// Written in C++ langs
// 2020. 03. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct XY{
    int x;
    int y;
}XY;

int COUNT;

int main(){
    ios_base :: sync_with_stdio(false);
    
    while(true){
        cin >> COUNT;
        if(COUNT == 0){
            return 0;
        }
        
        vector<int> lotto;
        int tmp;
        for(int i=0; i<COUNT; i++){
            cin >> tmp;
            lotto.push_back(tmp);
        }
        sort(lotto.begin(), lotto.end());
        
        vector<int> v;
        for(int i=0; i<COUNT; i++){
            if(i<6){
                v.push_back(0);
            }
            else{
                v.push_back(1);
            }
        }
        
        do{
            for(int i=0; i<v.size(); i++){
                if(v.at(i) == 0){
                    cout <<  lotto[i] << " ";
                }
            }
            cout << "\n";
        } while(next_permutation(v.begin(), v.end()));
        
        cout << "\n";
    }
    
    return 0;
    
}

