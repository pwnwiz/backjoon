// https://www.acmicpc.net/problem/6416
// 트리인가?
// Written in C++ langs
// 2020. 05. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set<int> SET;
vector<pair<int,int>> EDGE;
vector<pair<bool,int>> VERTEX;
vector<vector<pair<int,int>>> GRAPH;
vector<bool> VISITED;

void bfs(int s){
    VISITED[s] = true;
    
    for(auto edge : GRAPH[s]){
        int from = edge.first;
        int to = edge.second;
        
        if(!VISITED[to]){
            bfs(to);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b;
    int stage = 0;
    
    while(true){
        SET.clear();
        EDGE.clear();
        g
        stage ++;
        int cnt = 0;
        int max_vertex = -1;
        
        while(true){
            cin >> a >> b;
            
            if(a==0 && b==0) break;
            if(a<0 || b<0) return 0;
            
            max_vertex = max(max_vertex, a);
            max_vertex = max(max_vertex, b);
            EDGE.push_back(make_pair(a,b));
            
            SET.insert(a);
            SET.insert(b);
            
            cnt++;
        }
        
        if(cnt == 0){
            cout << "Case " << stage << " is a tree.\n";
            continue;
        }

        VERTEX.clear();
        VERTEX.resize(max_vertex+1);
        GRAPH.clear();
        GRAPH.resize(VERTEX.size());
        
        for(auto v : VERTEX){
            v.first = false;
            v.second = 0;
        }
        
        bool flag = false;
        for(auto e : EDGE){
            int from = e.first;
            int to = e.second;
            VERTEX[from].first = true;
            VERTEX[to].first = true;
            VERTEX[to].second += 1;
            
            if(VERTEX[to].second > 1){
                flag = true;
                break;
            }
            
            GRAPH[from].push_back(e);
        }
        
        if(flag){
            cout << "Case " << stage << " is not a tree.\n";
            continue;
        }
        
        if(cnt == SET.size()-1){
            int root = -1;
            int root_cnt = 0;
            for(int i=0; i<VERTEX.size(); i++){
                if(VERTEX[i].first && !VERTEX[i].second){
                    root = i;
                    root_cnt++;
                }
            }
            
            if(root_cnt!=1){
               cout << "Case " << stage << " is not a tree.\n";
            }
            
            else {
                VISITED.resize(VERTEX.size());
                fill(VISITED.begin(), VISITED.end(), false);
                
                bfs(root);
                
                int tc = 0;
                for(int i=0; i<VISITED.size(); i++){
                    if(VISITED[i]) tc++;
                }

                if(tc != SET.size()){
                    cout << "Case " << stage << " is not a tree.\n";
                }
                else {
                    cout << "Case " << stage << " is a tree.\n";
                }
            }
        } else {
            cout << "Case " << stage << " is not a tree.\n";
        }
    }
    
    return 0;
    
}

