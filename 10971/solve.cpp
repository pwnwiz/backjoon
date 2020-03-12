// https://www.acmicpc.net/problem/10971
// 외판원 순회 2
// Written in C++ langs
// 2020. 03. 12.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int CITY[11][11] = {0,};
bool VISITED[11] = {0,};
long long MIN_SUM = 999999999;
int N;

void dfs(int start, int cur, int sum, int cnt){
    if(start == cur && cnt == N){
        if(sum < MIN_SUM){
            MIN_SUM = sum;
        }
        return;
    }
    
    for(int i=0; i<N; i++){
        if(CITY[cur][i] == 0){
            continue;
        }
        
        else if(CITY[cur][i] != 0 && !VISITED[cur]){
            VISITED[cur] = true;
            if(sum + CITY[cur][i] < MIN_SUM){
                dfs(start, i, sum+CITY[cur][i], cnt+1);
            }
            VISITED[cur] = false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> CITY[i][j];
        }
    }
    
    for(int i=0; i<N; i++){
        dfs(i, i, 0, 0);
    }
    
    cout << MIN_SUM << "\n";
    
    return 0;
    
}

