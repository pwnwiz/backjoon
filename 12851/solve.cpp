// https://www.acmicpc.net/problem/12851
// 숨바꼭질 2
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

int MIN_V = -1;
int CNT = 0;
int VISITED[100001];

void bfs(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,N});
    VISITED[N] = 1;
    
    while(!pq.empty()){
        int cnt = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(MIN_V != -1 && cnt>MIN_V) continue;
        
        if(cur == K){
            if(MIN_V == -1) MIN_V = cnt;
            CNT++;
        }
        
        if(cur+1<=100000){
            if(!VISITED[cur+1] || VISITED[cur+1]>=cnt+1){
                VISITED[cur+1] = cnt+1;
                pq.push({cnt+1, cur+1});
            }
        }
        if(cur-1>=0){
            if(!VISITED[cur-1] || VISITED[cur-1]>=cnt+1){
                VISITED[cur-1] = cnt+1;
                pq.push({cnt+1, cur-1});
            }
        }
        if(cur*2<=100000){
            if(!VISITED[cur*2] || VISITED[cur*2]>=cnt+1){
                VISITED[cur*2] = cnt*2;
                pq.push({cnt+1, cur*2});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    
    bfs();
    
    cout << MIN_V << "\n";
    cout << CNT << "\n";
    return 0;
}

