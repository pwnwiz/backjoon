// https://www.acmicpc.net/problem/8111
// 0과 1
// Written in C++ langs
// 2020. 10. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int T, N;

void bfs(){
    bool visited[20001] = {0,};
    int parent[20001][2] = {0,};
    
    if(N == 1){
        cout << 1 << "\n";
        return;
    }
    
    queue<int> que;
    que.push(1);
    visited[1] = true;
    
    while(!que.empty()){
        int c = que.front();
        que.pop();
        
        // Modular
        // (1000 * 10 + 1) % 7 == ((1000 % 7) * 10 + 1) % 7
        int next[2] = {0,};
        next[0] = (c * 10) % N;
        next[1] = (c * 10 +1) % N;
        
        for(int i=0; i<2; i++){
            if(visited[next[i]]) continue;
            
            parent[next[i]][0] = c;
            parent[next[i]][1] = i;
            
            if(next[i] == 0){
                vector<int> result;
                result.push_back(parent[next[i]][1]);
                
                for(int n=parent[next[i]][0]; n!=1; n=parent[n][0]){
                    result.push_back(parent[n][1]);
                }
                result.push_back(1);
                reverse(result.begin(), result.end());
                
                for(auto r : result){
                    cout << r;
                }
                cout << "\n";
                return;
            }
            
            visited[next[i]] = true;
            que.push(next[i]);
        }
    }
    cout << "BRAK\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> N;
        
        bfs();
        
    }
    
    
    return 0;
    
}

