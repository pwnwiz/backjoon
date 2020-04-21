// https://www.acmicpc.net/problem/1647
// 도시 분할 계획
// Written in C++ langs
// 2020. 04. 21.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
vector<vector<pair<int,int>>> EDGE;
bool VISITED[100001]={0,};

int A, B;
long long RESULT = 0 ;
int MAX_WEIGHT = 0;

void prim(int s){
    VISITED[s] = true;
    
    for(auto e : EDGE[s]){
        if(!VISITED[e.second]){
            PQ.push(make_pair(e.first, e.second));
        }
    }
    
    while(!PQ.empty()){
        auto t = PQ.top();
        PQ.pop();
        
        if(!VISITED[t.second]){
            RESULT += t.first;
            MAX_WEIGHT = max(MAX_WEIGHT, t.first);
            prim(t.second);
            return;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    EDGE.resize(A+1);
    
    int a, b, w;
    for(int i=0; i<B; i++){
        cin >> a >> b >> w;
        EDGE[a].push_back(make_pair(w,b));
        EDGE[b].push_back(make_pair(w,a));
    }
    
    prim(1);
    
    cout << RESULT - MAX_WEIGHT << "\n";
    
    return 0;
}

