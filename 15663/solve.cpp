// https://www.acmicpc.net/problem/15663
// N과 M (9)
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> s;
vector<bool> VISITED;
vector<int> V;
int N, M;

void backtracking(int pos, vector<int> &v){
    
    if(pos == M){
        s.insert(v);
        return;
    }
    
    for(int i=0; i<V.size(); i++){
        if(VISITED[i]) continue;
        
        VISITED[i] = true;
        v.push_back(V[i]);
        backtracking(pos+1, v);
        VISITED[i] = false;
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
    
    for(auto ss : s){
        for(auto sss : ss){
            cout << sss << " ";
        }
        cout << "\n";
    }
    return 0;
    
}

