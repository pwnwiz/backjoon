// https://www.acmicpc.net/problem/2630
// 색종이 만들기
// Written in C++ langs
// 2020. 03. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

enum{
    WHITE=0,
    BLUE=1,
};

int N;
int PAPER[128][128] = {0,};
int BLUE_COUNT=0;
int WHITE_COUNT=0;

using namespace std;

void dc(int size, int x1, int y1){
    
    if(x1>=N || y1>=N){
        return;
    }
    
    int blue_count = 0;
    for(int i=x1; i<x1+size; i++){
        for(int j=y1; j<y1+size; j++){
            if(PAPER[i][j] == BLUE){
                blue_count++;
            }
        }
    }
    if(blue_count == size*size){
        BLUE_COUNT++;
        return;
    }
    
    if(blue_count == 0){
        WHITE_COUNT++;
        return;
    }
    
    int new_size = size/2;
    dc(new_size, x1, y1);
    dc(new_size, x1+new_size, y1);
    dc(new_size, x1, y1+new_size);
    dc(new_size, x1+new_size, y1+new_size);
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> PAPER[i][j];
        }
    }
    
    dc(N, 0, 0);
    cout << WHITE_COUNT << "\n";
    cout << BLUE_COUNT << "\n";
    
    return 0;
    
}

