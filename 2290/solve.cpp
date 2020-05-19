// https://www.acmicpc.net/problem/2290
// LCD Test
// Written in C++ langs
// 2020. 05. 19.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

char MAP[24][130]={0,};

bool segment[10][8] = {
    {1,1,1,0,1,1,1}, // zero
    {0,1,0,0,1,0,0}, // one
    {1,1,0,1,0,1,1}, // two
    {1,1,0,1,1,0,1}, // three
    {0,1,1,1,1,0,0}, // four
    {1,0,1,1,1,0,1}, // five
    {1,0,1,1,1,1,1}, // six
    {1,1,0,0,1,0,0}, // seven
    {1,1,1,1,1,1,1}, // eight
    {1,1,1,1,1,0,1}, // nine
};

int N;
string input;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> input;
    
    int x = 0;
    int y = 0;
    
    for(int i=0; i<input.size(); i++){
        int now = input[i] - '0';
        
        if(segment[now][0]) for(int i=x+1; i<x+N+1; i++) MAP[y][i] = '-';
        if(segment[now][1]) for(int i=y+1; i<y+N+1; i++) MAP[i][x+N+1] = '|';
        if(segment[now][2]) for(int i=y+1; i<y+N+1; i++) MAP[i][x] = '|';
        if(segment[now][3]) for(int i=x+1; i<x+N+1; i++) MAP[y+N+1][i] = '-';
        if(segment[now][4]) for(int i=y+N+1+1; i<y+2*N+2; i++) MAP[i][x+N+1] = '|';
        if(segment[now][5]) for(int i=y+N+1+1; i<y+2*N+2; i++) MAP[i][x] = '|';
        if(segment[now][6]) for(int i=x+1; i<x+N+1; i++) MAP[y+2*N+2][i] = '-';
        
        x += N+2+1;
    }
    
    
    for(int i=0; i<N*2+3; i++){
        for(int j=0; j<input.size()*(N+2+1); j++){
            if(MAP[i][j]!='|' && MAP[i][j]!='-') cout << " ";
            else cout << MAP[i][j];
        }
        cout << "\n";
    }
    
    return 0;
    
}

