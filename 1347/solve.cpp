// https://www.acmicpc.net/problem/1347
// 미로 만들기
// Written in C++ langs
// 2020. 07. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

bool MAP[200][200];

int N;
int X = 100;
int Y = 100;

int MIN_X = 100;
int MAX_X = 100;

int MIN_Y = 100;
int MAX_Y = 100;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char direction = 'S';

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    MAP[X][Y] = 1;
    
    char c;
    for(int i=0; i<N; i++){
        cin >> c;

        switch(c){
            case 'R':
                if(direction == 'S'){
                    direction = 'W';
                } else if (direction == 'E'){
                    direction = 'S';
                } else if (direction == 'W'){
                    direction = 'N';
                } else if (direction == 'N'){
                    direction = 'E';
                }
                break;
            case 'L':
                if(direction == 'S'){
                    direction = 'E';
                } else if (direction == 'E'){
                    direction = 'N';
                } else if (direction == 'W'){
                    direction = 'S';
                } else if (direction == 'N'){
                    direction = 'W';
                }
                break;
            case 'F':
                switch (direction) {
                    case 'W':
                        X += dx[1];
                        Y += dy[1];
                        break;
                    case 'S':
                        X += dx[2];
                        Y += dy[2];
                        break;
                    case 'N':
                        X += dx[3];
                        Y += dy[3];
                        break;
                    case 'E':
                        X += dx[0];
                        Y += dy[0];
                        break;
                }
                MAP[Y][X] = true;
                MIN_X = min(MIN_X, X);
                MAX_X = max(MAX_X, X);
                MIN_Y = min(MIN_Y, Y);
                MAX_Y = max(MAX_Y, Y);
                break;
        }
    }
    
    for(int i=MIN_Y; i<=MAX_Y; i++){
        for(int j=MIN_X; j<=MAX_X; j++){
            if(MAP[i][j]) cout << ".";
            else cout << "#";
        }
        cout << "\n";
    }
    
    return 0;
}

