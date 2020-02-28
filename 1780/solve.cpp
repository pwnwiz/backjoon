// https://www.acmicpc.net/problem/1780
// 종이의 개수
// Written in C++ langs
// 2020. 02. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int MAP[3000][3000]={0,};
int N;
int RES[3]={0,};

bool check(int X, int Y, int Size){
    for(int i=X; i<X+Size; i++){
        for(int j=Y; j<Y+Size; j++){
            if(MAP[X][Y] != MAP[i][j]) return false;
        }
    }
    return true;
}

void dc(int X, int Y, int Size){
    if(check(X, Y, Size)){
        RES[MAP[X][Y]+1]+=1;
        return;
    }
    
    else{
        int newSize = Size/3;
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                dc(X+newSize*i, Y+newSize*j, newSize);
            }
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
            cin >> MAP[i][j];
        }
    }
    
    dc(0,0,N);
 
    for(int i=0; i<3; i++){
        cout << RES[i] << "\n";
    }
}

