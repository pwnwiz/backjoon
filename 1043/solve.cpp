// https://www.acmicpc.net/problem/1043
// 거짓말
// Written in C++ langs
// 2020. 08. 11.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> truth;
vector<vector<int>> tp;
vector<vector<int>> edge;
vector<bool> visited;

int N, M, T;

void dfs(int s){
    visited[s] = true;
    
    for(auto n : edge[s]){
        if(!visited[n]){
            dfs(n);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    edge.resize(N+1);
    visited.resize(N+1, false);
    
    cin >> T;
    
    int input;
    for(int t=0; t<T; t++){
        cin >> input;
        truth.push_back(input);
    }

    int no;
    for(int m=0; m<M; m++){
        cin >> no;
        
        vector<int> party;
        
        for(int n=0; n<no; n++){
            cin >> input;
            
            party.push_back(input);
        }
        
        for(int i=0; i<party.size()-1; i++){
            for(int j=i+1; j<party.size(); j++){
                edge[party[i]].push_back(party[j]);
                edge[party[j]].push_back(party[i]);
            }
        }
        
        tp.push_back(party);
    }
    
    for(auto t: truth){
        dfs(t);
    }
    
    int result = 0;
    for(int i=0; i<tp.size(); i++){
        bool flag = false;
        for(auto p : tp[i]){
            if(visited[p]){
                flag = true;
                break;
            }
        }
        
        if(!flag) result++;
    }

    cout << result << "\n";
    
    return 0;
}

