// https://www.acmicpc.net/problem/15655
// N과 M (6)
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
        auto v2 = v;
        sort(v2.begin(), v2.end());
        
        if(find(VV.begin(), VV.end(), v2) == VV.end()){
            VV.push_back(v2);
        }
        
        return;
    }
    
    for(int i=0; i<V.size(); i++){
        if(VISITED[i]) continue;
        
        VISITED[i] = true;
        v.push_back(V[i]);
        backtracking(pos+1, v);
        v.pop_back();
        VISITED[i] = false;
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

