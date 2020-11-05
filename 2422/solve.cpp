// https://www.acmicpc.net/problem/2422
// 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
// Written in C++ langs
// 2020. 11. 05.
// Wizley

#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

using namespace std;

bool match[201][201];
bool used[201];

int N, M;

long long result = 0;
void backtracking(int start, int cnt){
    
    if(cnt == 3){
        result ++;
        return;
    }
    
    for(int next=start; next<=N; next++){
        if(used[next]) continue;
        
        bool flag = true;
        for(int i=1; i<=N; i++){
            if(!used[i]) continue;
            if(match[i][next] || match[next][i]){
                flag = false;
                break;
            }
        }
            
        if(flag){
            used[next] = true;
            backtracking(next+1, cnt+1);
            used[next] = false;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    int a, b;
    for(int m=0; m<M; m++){
        cin >> a >> b;
        match[a][b] = true;
        match[b][a] = true;
    }
    
    backtracking(1, 0);
    
    cout << result << "\n";
    return 0;
    
}

