// https://www.acmicpc.net/problem/1049
// 기타줄
// Written in C++ langs
// 2020. 04. 01.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int PACKAGE[50]={0,};
int EACH[50]={0,};
int SIX=0;
int TOTAL=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        cin >> PACKAGE[i] >> EACH[i];
    }
    
    sort(PACKAGE, PACKAGE+M);
    sort(EACH, EACH+M);
    SIX = EACH[0]*6;

    while(N>0){
        if(N>=6){
            TOTAL += min(SIX, PACKAGE[0]);
            N -= 6;
        }
        else{
            if(EACH[0]*N <= PACKAGE[0]){
                TOTAL += EACH[0]*N;
                N = 0;
            }
            else{
                TOTAL += PACKAGE[0];
                N = 0;
            }
        }
    }

    cout << TOTAL << "\n";
    
    return 0;
    
}

