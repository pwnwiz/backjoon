// https://www.acmicpc.net/problem/15652
// N과 M (4)
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

vector<vector<int>> vvec;

void backtracking(int pos, vector<int> &v){
    
    if(pos == M){
        vvec.push_back(v);
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(!v.empty() && v.back() > i) continue;
        
        v.push_back(i);
        backtracking(pos+1, v);
        v.pop_back();
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    vector<int> v;
    backtracking(0, v);
    
    sort(vvec.begin(), vvec.end());
    
    for(auto vec : vvec){
        for(auto vc : vec){
            cout << vc << " ";
        }
        cout << "\n";
    }
    
    return 0;
    
}

