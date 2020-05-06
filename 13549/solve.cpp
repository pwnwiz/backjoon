// https://www.acmicpc.net/problem/13549
// 숨바꼭질 3
// Written in C++ langs
// 2020. 05. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <tuple>
#include <math.h>

#define INF 99999999999

using namespace std;

using namespace std;
int N, K;
int VISITED[100001]={0,};

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    pq.push(make_pair(0,s));
    
    VISITED[s] = 0;
    
    while(!pq.empty()){
        int cnt = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(cur*2 >=0 && cur*2 <=100000 && VISITED[cur*2] > cnt){
            VISITED[cur*2] = cnt;
            pq.push(make_pair(cnt, cur*2));
        }
        
        if(cur+1 >=0 && cur+1 <=100000 && VISITED[cur+1] > cnt+1){
            VISITED[cur+1] = cnt+1;
            pq.push(make_pair(cnt+1, cur+1));
        }
        
        if(cur-1 >=0 && cur-1 <=100000 && VISITED[cur-1] > cnt+1){
            VISITED[cur-1] = cnt+1;
            pq.push(make_pair(cnt+1, cur-1));
        }
    }
}

int main(){
    cin >> N >> K;
    
    fill(VISITED, VISITED+100001, INF);
    dijkstra(N);
    
    cout << VISITED[K] << "\n";
    return 0;
    
}

