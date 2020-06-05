// https://www.acmicpc.net/problem/1199
// 오일러 회로
// Written in C++ langs
// 2020. 06. 05.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ARR[1001][1001];
int INDEGREE[1001];
vector<int> RESULT;
int N;

// eulrianCircuit
// 오일러 회로
void dfs(int s){
    
    for(int i=1; i<=N; i++){
        
        if(i==s) continue;
        
        // INDEGREE를 줄이면서 dfs 돌림
        // 두 정점사이에 간선이 여러 개 존재할 수 있음
        while(ARR[s][i]){
            ARR[s][i]--;
            ARR[i][s]--;
            dfs(i);
        }
    }
    
    RESULT.push_back(s);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> ARR[i][j];
            // 1보다 큰 값이 들어올 수 있음
            INDEGREE[j] += ARR[i][j];
        }
    }
    
    // 정점으로 가는 edge가 존재하는데 짝수가 아닌 경우
    // 만약 정점으로 가는 어떠한 edge도 존재하지 않을 경우에는 상관이 없음
    for(int i=1; i<=N; i++){
        if(INDEGREE[i]%2!=0 && INDEGREE[i]){
            cout << "-1\n";
            exit(0);
        }
    }
    
    dfs(1);
    
    reverse(RESULT.begin(), RESULT.end());
    for(auto r : RESULT){
        cout << r << " ";
    }
    cout << "\n";
    
    return 0;
    
}

