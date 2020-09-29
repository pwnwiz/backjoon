// https://www.acmicpc.net/problem/15657
// N과 M (8)
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> VV;

vector<bool> VISITED;
vector<int> V;
int N, M;

void backtracking(int pos, vector<int> &v){
    
    if(pos == M){
        VV.push_back(v);
        return;
    }
    
    for(int i=0; i<V.size(); i++){
        if(!v.empty() and V[i] < v.back()) continue;
        
        v.push_back(V[i]);
        backtracking(pos+1, v);
        v.pop_back();
    }
    
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    V.resize(N);
    VISITED.resize(N);
    
    for(int i=0; i<N; i++){
        cin >> V[i];
    }
    
    sort(V.begin(), V.end());
    
    vector<int> vv;
    backtracking(0, vv);
    
    for(auto vvv : VV){
        for(auto vc : vvv){
            cout << vc << " ";
        }
        cout << "\n";
    }
    
    return 0;
    
}

