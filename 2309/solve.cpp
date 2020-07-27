// https://www.acmicpc.net/problem/2309
// 일곱 난쟁이
// Written in C++ langs
// 2020. 07. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> dwarf(9);
    vector<int> result;
    
    for(int i=0; i<9; i++){
        cin >> dwarf[i];
    }
    
    vector<int> permute(9);
    int cnt = 0;
    for(int i=0; i<9; i++){
        if(cnt < 7){
            permute[i] = 1;
            cnt++;
        } else {
            permute[i] = 0;
        }
    }
    
    sort(permute.begin(), permute.end());
    
    do {
        int tc = 0;
        for(int p=0; p<permute.size(); p++){
            if(permute[p]){
                tc += dwarf[p];
            }
        }
        
        if(tc == 100){
            for(int t=0; t<permute.size(); t++){
                if(permute[t]){
                    result.push_back(dwarf[t]);
                }
            }
            break;
        }
        
    } while(next_permutation(permute.begin(), permute.end()));
    
    sort(result.begin(), result.end());
    
    for(auto r : result){
        cout << r << "\n";
    }
    
    
    return 0;
}

