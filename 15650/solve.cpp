// https://www.acmicpc.net/problem/15650
// N과 M (2)
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> vvec;
bool VISITED[9];

void backtracking(int pos, vector<int> &v){
    
    if(pos == M){
        auto v2 = v;
        sort(v2.begin(), v2.end());
        if(find(vvec.begin(), vvec.end(), v2) == vvec.end()){
            vvec.push_back(v);
            for(auto n : v2){
                cout << n << " ";
            }
            cout << "\n";
        }
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(VISITED[i]) continue;
        
        VISITED[i] = true;
        v.push_back(i);
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

    vector<int> v;
    backtracking(0, v);
    
    
    return 0;
    
}

