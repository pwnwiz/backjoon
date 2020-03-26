// https://www.acmicpc.net/problem/1074
// Z
// Written in C++ langs
// 2020. 03. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

int N;
int IDX=0;
int X, Y;

void dc(int size, int x, int y){
    if(x == X && y == Y){
        cout << IDX << "\n";
        exit(0);
    }
    
    if(size == 1){
        IDX ++;
        return;
    }
    
    if(x>X || y>Y || x+size<=X || y+size<=Y){
        IDX += size*size;
        return;
    }
    
    int new_size = size/2;
    dc(new_size, x, y);
    dc(new_size, x, y+new_size);
    dc(new_size, x+new_size, y);
    dc(new_size, x+new_size, y+new_size);

}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> X >> Y;
    
    dc(pow(2,N), 0, 0);
    
    return 0;
    
}

