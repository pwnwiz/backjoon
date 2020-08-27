// https://www.acmicpc.net/problem/4803
// 트리
// Written in C++ langs
// 2020. 08. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> VERTEX;
vector<bool> VISITED;
vector<bool> CYCLE;
vector<vector<int>> EDGE;
int N, M;

bool checkCycle(int prev, int pos){
    // if meets cycle
    if(CYCLE[pos]) return true;
    
    // if meets other tree
    if(VISITED[pos]) return false;
    
    VISITED[pos] = true;
    
    // backtracking
    CYCLE[pos] = true;
    for(auto next: EDGE[pos]){
        if(next == prev) continue;
    
        if(checkCycle(pos, next)) return true;
    }
    CYCLE[pos] = false;
    
    return false;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int caseNo = 1;
    while(true){
        int cnt = 0;
        cin >> N >> M;
        
        if(N==0 && M==0) break;
        
        VERTEX.clear();
        EDGE.clear();
        VERTEX.resize(N+1);
        EDGE.resize(N+1);
        VISITED.clear();
        VISITED.resize(N+1);
        CYCLE.clear();
        CYCLE.resize(N+1);
        
        int a, b;
        for(int m=0; m<M; m++){
            cin >> a >> b;
            EDGE[a].push_back(b);
            EDGE[b].push_back(a);
        }
        
        cout << "Case " << caseNo << ": ";
        
        for(int i=1; i<=N; i++){
            if(!VISITED[i] && !checkCycle(0, i)){
                cnt++;
            }
        }
        
        switch(cnt){
            case 0:
                cout << "No trees.\n";
                break;
            case 1:
                cout << "There is one tree.\n";
                break;
            default:
                cout << "A forest of " << cnt << " trees.\n";
                break;
        }
        
        caseNo++;
    }
    
    
    return 0;

}

