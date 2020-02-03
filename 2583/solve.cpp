// https://www.acmicpc.net/problem/2583
// 영역 구하기
// Written in C++ langs
// 2020. 02. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum{
    VISIT=2
};

int MATRIX[101][101]={0,};
int M, N, K;
vector<int> RESULT;

void addRectangle(int x1, int y1, int x2, int y2){
    for(int i=y1; i<y2; i++){
        for(int j=x1; j<x2; j++){
            MATRIX[i][j] = 1;
        }
    }
}

int DFS(int X, int Y){
    int count = 1;
    MATRIX[X][Y] = VISIT;
    
    int DIRECT_X[4] = {-1, 0, 1, 0};
    int DIRECT_Y[4] = {0, -1, 0, 1};

    for(int i=0; i<4; i++){
        int new_X = X + DIRECT_X[i];
        int new_Y = Y + DIRECT_Y[i];
        
        if(new_X>=0 && new_Y>=0 && new_X<M && new_Y<N){
            if(!MATRIX[new_X][new_Y]) count += DFS(new_X, new_Y);
        }
    }
    return count;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    
    int x1, y1, x2, y2;
    
    for(int i=0; i<K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        addRectangle(x1,y1,x2,y2);
    }
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(!MATRIX[i][j]) RESULT.push_back(DFS(i, j));
        }
    }

    sort(RESULT.begin(), RESULT.end());
    cout << RESULT.size() << "\n";
    
    for(int i=0; i<RESULT.size(); i++){
        cout << RESULT[i] << " ";
    }
    cout << "\n";
    
    return 0;

}

