// https://www.acmicpc.net/problem/3967
// 매직 스타
// Written in C++ langs
// 2020. 04. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N;
char STAR[5][9]={0,};
int VISITED[12]={0,};

vector<pair<int,int>> X;
int X_COUNT=0;

bool checkStar(){
    if((STAR[0][4]-'A') + (STAR[1][3]-'A') + (STAR[2][2]-'A') + (STAR[3][1]-'A') != (26-4)) return false;
    if((STAR[0][4]-'A') + (STAR[1][5]-'A') + (STAR[2][6]-'A') + (STAR[3][7]-'A') != (26-4)) return false;
    if((STAR[1][1]-'A') + (STAR[1][3]-'A') + (STAR[1][5]-'A') + (STAR[1][7]-'A') != (26-4)) return false;
    if((STAR[1][1]-'A') + (STAR[2][2]-'A') + (STAR[3][3]-'A') + (STAR[4][4]-'A') != (26-4)) return false;
    if((STAR[1][7]-'A') + (STAR[2][6]-'A') + (STAR[3][5]-'A') + (STAR[4][4]-'A') != (26-4)) return false;
    if((STAR[3][1]-'A') + (STAR[3][3]-'A') + (STAR[3][5]-'A') + (STAR[3][7]-'A') != (26-4)) return false;
    return true;
}

void printStar(){
    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            cout << STAR[i][j];
        }
        cout << "\n";
    }
}

void dfs(int idx, int count){
    if(count == X_COUNT){
        if(checkStar()){
            printStar();
            exit(0);
        }
        return;
    }
    
    for(int i=0; i<12; i++){
        if(!VISITED[i]){
            int x = X[idx].first;
            int y = X[idx].second;
            
            STAR[x][y] = 'A' + i;
            VISITED[i] = true;
            
            dfs(idx+1, count+1);
            
            STAR[x][y] = 'x';
            VISITED[i] = false;
            
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<5; i++){
        for(int j=0; j<9; j++){
            cin >> STAR[i][j];
            if(STAR[i][j]>='A' && STAR[i][j]<='L'){
                VISITED[STAR[i][j]-'A'] = true;
            }
            if(STAR[i][j]=='x'){
                X.push_back(make_pair(i,j));
                X_COUNT++;
            }
            
        }
    }
    
    dfs(0, 0);
    
    return 0;
    
}

