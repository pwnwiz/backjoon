// https://www.acmicpc.net/problem/8911
// 거북이
// Written in C++ langs
// 2020. 05. 14.
// Wizley

#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

vector<pair<int,int>> V;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bx[] = {1,-1,0,0};
int by[] = {0,0,1,-1};

int N;
string INPUT;

void getWidth(){
    pair<int,int> X;
    pair<int,int> Y;
    for(int i=0; i<V.size(); i++){
        if(i==0){
            X.first = X.second = V[i].first;
            Y.first = Y.second =  V[i].second;
        }
        else {
            X.first = min(X.first, V[i].first);
            X.second = max(X.second, V[i].first);
            Y.first = min(Y.first, V[i].second);
            Y.second = max(Y.second, V[i].second);
        }
    }
    V.clear();
    cout << (X.second - X.first) * (Y.second - Y.first) << "\n";
}

void bfs(){
    V.push_back(make_pair(500,500));
    int direct = 0;
    
    int nx = 500;
    int ny = 500;
    
    for(int i=0; i<INPUT.size(); i++){
        switch(INPUT[i]){
            case 'F':
                nx = nx + dx[direct];
                ny = ny + dy[direct];
                V.push_back(make_pair(nx,ny));
                break;
            case 'B':
                nx = nx + bx[direct];
                ny = ny + by[direct];
                V.push_back(make_pair(nx,ny));
                break;
            case 'L':
                switch(direct){
                    case 0:
                        direct = 2;
                        break;
                    case 1:
                        direct = 3;
                        break;
                    case 2:
                        direct = 1;
                        break;
                    case 3:
                        direct = 0;
                        break;
                }
                break;
            case 'R':
                switch(direct){
                    case 0:
                        direct = 3;
                        break;
                    case 1:
                        direct = 2;
                        break;
                    case 2:
                        direct = 0;
                        break;
                    case 3:
                        direct = 1;
                        break;
                }
                break;
        }
    }
    
    getWidth();
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> INPUT;
        bfs();
    }
    
    return 0;
    
    
    
}

