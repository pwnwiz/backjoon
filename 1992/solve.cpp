// https://www.acmicpc.net/problem/1992
// 쿼드트리
// Written in C++ langs
// 2020. 03. 02.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

char DATA[64][64]={0,};
int N;

bool check(int x, int y, int size){
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(DATA[i][j] != DATA[x][y])
                return false;
        }
    }
    return true;
}

void dc(int x, int y, int size){
    if(check(x, y, size)){
        cout << DATA[x][y];
    }
    
    else{
        
        int new_size = size/2;
        cout << "(";
        
        if(size==1){
            cout << DATA[x][y];
            return;
        }
        
        int val_x[4] = {0, 0, new_size, new_size};
        int val_y[4] = {0, new_size, 0, new_size};
        for(int i=0; i<4; i++){
            if(check(x+val_x[i], y+val_y[i], new_size)){
                cout << DATA[x+val_x[i]][y+val_y[i]];
            }
            else{
                dc(x+val_x[i], y+val_y[i], new_size);
            }
        }
        cout << ")";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> DATA[i][j];
        }
    }
    
    dc(0,0,N);
    cout << "\n";
    
    return 0;
}

