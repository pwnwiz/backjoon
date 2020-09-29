// https://www.acmicpc.net/problem/15651
// N과 M (3)
// Written in C++ langs
// 2020. 09. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

void backtracking(int pos, vector<int> &v){
    
    if(pos == M){
        for(auto n : v){
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=1; i<=N; i++){
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
    
    
    return 0;
    
}

