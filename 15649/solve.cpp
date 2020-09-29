// https://www.acmicpc.net/problem/15649
// N과 M (1)
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool VISITED[9];
void backtracking(int pos, vector<int> &v){
    
    if(pos == M){
        for(auto n : v){
            cout << n << " ";
        }
        cout << "\n";
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

