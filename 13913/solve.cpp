// https://www.acmicpc.net/problem/13913
// 숨바꼭질 4
// Written in C++ langs
// 2020. 10. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, K;

bool VISITED[100001];
int ROUTE[100001];

void bfs(){
    queue<pair<int,int>> que;
    VISITED[N] = true;
    que.push({N,0});
    
    while(!que.empty()){
        int cur = que.front().first;
        int cnt = que.front().second;
        
        que.pop();
        
        if(cur == K){
            cout << cnt << "\n";
            
            vector<int> routes;
            
            for(int s=K; s!=N; s=ROUTE[s]){
                routes.push_back(s);
            }
            routes.push_back(N);
            
            reverse(routes.begin(), routes.end());
            for(auto r : routes){
                cout << r << " ";
            }
            cout << "\n";
            
            break;
        }
        
        if(cur+1<=100000 && !VISITED[cur+1]){
            VISITED[cur+1] = true;
            que.push({cur+1, cnt+1});
            ROUTE[cur+1] = cur;
        }
        
        if(cur-1>=0 && !VISITED[cur-1]){
            VISITED[cur-1] = true;
            que.push({cur-1, cnt+1});
            ROUTE[cur-1] = cur;
        }
        
        if(cur*2<=100000 && !VISITED[cur*2]){
            VISITED[cur*2] = true;
            que.push({cur*2, cnt+1});
            ROUTE[cur*2] = cur;
        }
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    bfs();
    
    return 0;
}

