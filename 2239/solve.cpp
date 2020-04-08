// https://www.acmicpc.net/problem/2239
// 스도쿠
// Written in C++ langs
// 2020. 04. 08.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<pair<int,int>> TODO;
int SUDOKU[9][9]={0,};
bool VISITED[9][9]={0,};

bool check_Horizontal(int x, int val){
    for(int i=0; i<9; i++){
        if(SUDOKU[x][i] == val) return false;
    }
    return true;
}

bool check_Vertical(int y, int val){
    for(int i=0; i<9; i++){
        if(SUDOKU[i][y] == val) return false;
    }
    return true;
}

bool check_Square(int x, int y, int val){
    x *= 3;
    y *= 3;
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if(SUDOKU[i][j] == val) return false;
        }
    }
    return true;
}

bool check(int x, int y, int val){
    if(!check_Horizontal(x, val)) return false;
    if(!check_Vertical(y, val)) return false;
    if(!check_Square(x/3, y/3, val)) return false;
    return true;
}

void backtracking(){
    if(TODO.empty()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << SUDOKU[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        exit(0);
    }
    
    int cur_x = TODO[0].first;
    int cur_y = TODO[0].second;
    
    for(int j=1; j<=9; j++){
        if(check(cur_x, cur_y, j)){
            SUDOKU[cur_x][cur_y] = j;
            TODO.erase(TODO.begin());
            
            backtracking();
            
            SUDOKU[cur_x][cur_y] = 0;
            TODO.insert(TODO.begin(), make_pair(cur_x,cur_y));
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    char input;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> input;
            SUDOKU[i][j] = input - '0';
            if(SUDOKU[i][j] == 0){
                TODO.push_back(make_pair(i,j));
            }
        }
    }
    
    backtracking();

    return 0;
    
}

