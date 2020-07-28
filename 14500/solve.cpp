// https://www.acmicpc.net/problem/14500
// 테트로미노
// Written in C++ langs
// 2020. 07. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int MAP[500][500];
int N, M;

int MAXV = 0;

void simulation(){
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            // x - - -
            if(j+3<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i][j+2]+MAP[i][j+3]);
            }
            
            // x
            // |
            // |
            // |
            if(i+3<N){
                MAXV = max(MAXV, MAP[i][j]+MAP[i+1][j]+MAP[i+2][j]+MAP[i+3][j]);
            }
            
            // x -
            // - -
            if(i+1<N && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i+1][j]+MAP[i+1][j+1]);
            }
            
            // x
            // |
            // | _
            if(i+2<N && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i+1][j]+MAP[i+2][j]+MAP[i+2][j+1]);
            }
            
            //  x
            //  |
            // _|
            if(i+2<N && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i+1][j]+MAP[i+2][j]+MAP[i+2][j-1]);
            }
            
            //
            //     |
            // x - -
            if(i-1>=0 && j+2<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i][j+2]+MAP[i-1][j+2]);
            }
            
            //
            // x - -
            //     |
            if(i+1<N && j+2<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i][j+2]+MAP[i+1][j+2]);
            }
            
            // - |
            //   |
            //   x
            if(i-2>=0 && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i-2][j]+MAP[i-2][j-1]);
            }
            
            // | -
            // |
            // x
            if(i-2>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i-2][j]+MAP[i-2][j+1]);
            }
            
            // - - x
            // |
            if(i+1<N && j-2>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i][j-2]+MAP[i+1][j-2]);
            }
            
            // |
            // - - x
            if(i-1>=0 && j-2>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i][j-2]+MAP[i-1][j-2]);
            }
            
            //
            // x
            // - - -
            if(i+1<N && j+2<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i+1][j]+MAP[i+1][j+1]+MAP[i+1][j+2]);
            }
            
            //
            //     x
            // - - -
            if(i+1<N && j-2>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i+1][j]+MAP[i+1][j-1]+MAP[i+1][j-2]);
            }
            
            //  |
            //  |
            // x|
            if(i-2>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i-1][j+1]+MAP[i-2][j+1]);
            }
            
            // x|
            //  |
            //  |
            if(i+2<N && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i+1][j+1]+MAP[i+2][j+1]);
            }
            
            // - - -
            //     x
            if(i-1>=0 && j-2>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i-1][j-1]+MAP[i-1][j-2]);
            }
            
            // - - -
            // x
            if(i-1>=0 && j+2<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i-1][j+1]+MAP[i-1][j+2]);
            }
            
            // |x
            // |
            // |
            if(i+2<N && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i+1][j-1]+MAP[i+2][j-1]);
            }
            
            // |
            // |
            // |x
            if(i-2>=0 && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i-1][j-1]+MAP[i-2][j-1]);
            }
            
            //   - -
            // - x
            if(i-1>=0 && j-1>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i-1][j]+MAP[i-1][j+1]);
            }
            
            // - x
            //   - -
            if(i+1<N && j-1>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i+1][j]+MAP[i+1][j+1]);
            }
            
            //   |
            // - x
            // |
            if(i-1>=0 && i+1<N && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i+1][j-1]+MAP[i-1][j]);
            }
            
            // |
            // x -
            //   |
            if(i-1>=0 && i+1<N && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i][j+1]+MAP[i+1][j+1]);
            }
            
            //   x -
            // - -
            if(i+1<N && j-1>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i+1][j]+MAP[i+1][j-1]);
            }
            
            // - -
            //   x -
            if(i-1>=0 && j-1>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i-1][j]+MAP[i-1][j-1]);
            }
            
            //   |
            // x |
            // |
            if(i-1>=0 && i+1<N && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j+1]+MAP[i-1][j+1]+MAP[i+1][j]);
            }
            
            // |
            // | x
            //   |
            if(i-1>=0 && i+1<N && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i+1][j]+MAP[i][j-1]+MAP[i-1][j-1]);
            }
            
            //   |
            // - x -
            if(i-1>=0 && j-1>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i][j-1]+MAP[i][j+1]);
            }
            
            // |
            // x -
            // |
            if(i-1>=0 && i+1<N && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i+1][j]+MAP[i][j+1]);
            }
            
            // - x -
            //   |
            if(i+1<N && j-1>=0 && j+1<M){
                MAXV = max(MAXV, MAP[i][j]+MAP[i][j-1]+MAP[i][j+1]+MAP[i+1][j]);
            }
            
            //   |
            // - |
            //   |
            if(i-1>=0 && i+1<N && j-1>=0){
                MAXV = max(MAXV, MAP[i][j]+MAP[i-1][j]+MAP[i+1][j]+MAP[i][j-1]);
            }
        }
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
        }
    }
    
    simulation();
    
    cout << MAXV << "\n";
    
    
    return 0;
}

