// https://www.acmicpc.net/problem/1697
// 숨바꼭질
// Written in C++ langs
// 2020. 03. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool VISITED[100001] = {0,};
int SEC = 9999999;

void bfs(){
    queue<int> que;
    que.push(N);
    VISITED[N] = true;
    
    int total_sec = 0;
    
    while(!que.empty()){
        queue<int> que2;
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            VISITED[cur] = true;
            if(cur == K){
                SEC = min(SEC, total_sec);
            }
            if(cur-1>=0 && cur-1<=100000 && !VISITED[cur-1]){
                que2.push(cur-1);
            }
            if(cur+1>=0 && cur+1<=100000 && !VISITED[cur+1]){
                que2.push(cur+1);
            }
            if(cur*2>=0 && cur*2<=100000 && !VISITED[cur*2]){
                que2.push(cur*2);
            }
        }
        que = que2;
        total_sec++;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    bfs();
    
    cout << SEC << "\n";
}

