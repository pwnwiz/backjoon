// https://www.acmicpc.net/problem/1949
// 우수 마을
// Written in C++ langs
// 2020. 08. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> VILLAGE;
vector<vector<int>> ROAD;
vector<bool> VISITED(10001, false);

int DP[10002][2];
int N;

void getTotal(int pos){

    VISITED[pos] = true;
    
    for(auto next: ROAD[pos]){
        if(VISITED[next]) continue;
        
        getTotal(next);
        
        // 현재 마을이 우수 마을인 경우
        // 다음 마을이 우수 마을로 선택될 수 없음
        DP[pos][1] += DP[next][0];
        
        // 현재 마을이 우수 마을이 아닌 경우는
        // 다음 마을이 우수 마을이거나 우수마을이 아닌 경우 중 큰 값
        DP[pos][0] += max(DP[next][1], DP[next][0]);
        
    }
    
    // 현재 마을이 우수 마을인 경우 사람 수를 더 해줌
    DP[pos][1] += VILLAGE[pos];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    VILLAGE.resize(N+1);
    ROAD.resize(N+1);
    
    for(int i=1; i<=N; i++){
        cin >> VILLAGE[i];
    }
    
    int a, b;
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        ROAD[a].push_back(b);
        ROAD[b].push_back(a);
    }

    getTotal(1);
    
    cout << max(DP[1][0], DP[1][1]) << "\n";
    
    return 0;
}

