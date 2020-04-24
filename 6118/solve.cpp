// https://www.acmicpc.net/problem/6118
// 숨바꼭질
// Written in C++ langs
// 2020. 04. 24.
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

#define INF 99999999

using namespace std;

vector<vector<int>> HUT(20002);
int DISTANCE[20002]={0,};

int N, M;

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    DISTANCE[1] = 0;
    pq.push(make_pair(0,1));
    
    while(!pq.empty()){
        int w = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        
        if(w > DISTANCE[x]) continue;
        
        for(auto e : HUT[x]){
            int y = e;
            
            if(DISTANCE[y] > w+1){
                DISTANCE[y] = w+1;
                pq.push(make_pair(w+1,y));
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        HUT[a].push_back(b);
        HUT[b].push_back(a);
    }
    
    fill(DISTANCE, DISTANCE+N+1, INF);
    dijkstra();
    
    int max_el = *max_element(DISTANCE+1, DISTANCE+N+1);
    int min_el = -1;
    int cnt = 0;
    for(int i=1; i<=N; i++){
        if(DISTANCE[i] == max_el){
            if(min_el == -1) min_el = i;
            cnt++;
        }
    }

    cout << min_el << " " << max_el << " " <<cnt << "\n";

}

