// https://www.acmicpc.net/problem/1236
// 성 지키기
// Written in C++ langs
// 2020. 08. 11.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

char MAP[50][50];
int N, M;

bool ROW[50];
bool COL[50];

void print(){
    cout << "\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << MAP[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            
            if(MAP[i][j] == 'X'){
                ROW[i] = true;
                COL[j] = true;
            }
        }
    }
  
    int row = 0;
    int col = 0;
    
    for(int i=0; i<N; i++){
        if(ROW[i]) row++;
    }
    
    for(int j=0; j<M; j++){
        if(COL[j]) col++;
    }

    cout << max(N-row, M-col) << "\n";
    return 0;
    
}

