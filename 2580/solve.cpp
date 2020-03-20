// https://www.acmicpc.net/problem/2580
// 스도쿠
// Written in C++ langs
// 2020. 03. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int SUDOKU[9][9]={0,};
vector<pair<int,int>> BLANK;

void print(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << SUDOKU[i][j] << " ";
        }
        cout << "\n";
    }
}

bool checkBox(int x, int y, int val){
    x = x/3;
    y = y/3;
    for(int i=x*3; i<x*3+3; i++){
        for(int j=y*3; j<y*3+3; j++){
            if(val == SUDOKU[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool checkHorizontal(int y, int val){
    for(int i=0; i<9; i++){
        if(val == SUDOKU[i][y]){
            return false;
        }
    }
    return true;
}

bool checkVertical(int x, int val){
    for(int i=0; i<9; i++){
        if(val == SUDOKU[x][i]){
            return false;
        }
    }
    return true;
}

void backtracking(int blank_idx){
    
    if(blank_idx == BLANK.size()){
        print();
        exit(0);
    }
    
    for(int i=1; i<=9; i++){
        int x = BLANK[blank_idx].first;
        int y = BLANK[blank_idx].second;
        
        if(checkBox(x, y, i) && checkVertical(x, i) && checkHorizontal(y, i)){
            SUDOKU[x][y] = i;
            backtracking(blank_idx + 1);
            SUDOKU[x][y] = 0;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> SUDOKU[i][j];
            if(SUDOKU[i][j] == 0){
                BLANK.push_back({i,j});
            }
        }
    }
    
    backtracking(0);

    return 0;
    
}

