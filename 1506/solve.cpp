// https://www.acmicpc.net/problem/1506
// 경찰서
// Written in C++ langs
// 2020. 04. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

int N;
int POLICE[100]={0,};
int VISITED[100]={0,};
char EDGE[100][100]={0,};

vector<int> SCC;
vector<vector<int>> CYCLES;
stack<int> STACK;

long long TOTAL=0;

void dfs(int idx, bool isInverse){
    VISITED[idx] = true;
    
    for(int i=0; i<N; i++){
        if(!isInverse){
            if(EDGE[idx][i] == '1' && !VISITED[i]){
                dfs(i, isInverse);
            }
        }
        
        else{
            if(EDGE[i][idx] == '1' && !VISITED[i]){
                dfs(i, isInverse);
            }
        }
    }
        
    if(isInverse) SCC.push_back(idx);
    else STACK.push(idx);
}

void kosaraju(){
    for(int i=0; i<N; i++){
        if(!VISITED[i]){
            dfs(i, false);
        }
    }
    
    memset(VISITED, false, sizeof(VISITED));
    
    while(STACK.size()){
        int v = STACK.top();
        SCC.clear();
        STACK.pop();
        
        if(!VISITED[v]){
            dfs(v, true);
            CYCLES.push_back(SCC);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> POLICE[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> EDGE[i][j];
        }
    }
    
    kosaraju();

    for(int i=0; i<CYCLES.size(); i++){
        int min_val = 9999999;
        for(int j=0; j<CYCLES[i].size(); j++){
            min_val = min(min_val, POLICE[CYCLES[i][j]]);
        }
        TOTAL += min_val;
    }

    cout << TOTAL << "\n";
    
    return 0;
    
}
