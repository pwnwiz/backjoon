// https://www.acmicpc.net/problem/1969
// DNA
// Written in C++ langs
// 2020. 04. 01.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char DNA[1000][50]={0,};
int COUNT=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> DNA[i][j];
        }
    }
    
    for(int i=0; i<M; i++){
        int A = 0;
        int T = 0;
        int G = 0;
        int C = 0;
        for(int j=0; j<N; j++){
            if(DNA[j][i] == 'A') A++;
            else if(DNA[j][i] == 'T') T++;
            else if(DNA[j][i] == 'G') G++;
            else C++;
        }
        
        if(A>=T && A>=G && A>=C){
            cout << "A";
            COUNT += T + G + C;
        }
        else if(C>=A && C>=T && C>=G){
            cout << "C";
            COUNT += A + T + G;
        }
        else if(G>=A && G>=T && G>=C){
            cout << "G";
            COUNT += A + T + C;
        }
        else{
            cout << "T";
            COUNT += A + G + C;
        }
    }
    
    cout << "\n" << COUNT << "\n";
    
    return 0;

}


