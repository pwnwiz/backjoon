// https://www.acmicpc.net/problem/4195
// 친구 네트워크
// Written in C++ langs
// 2020. 04. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <tuple>
#include <math.h>

using namespace std;

map<string,int> NETWORK;
int SET[200001]={0,};
int COUNT[200001]={0,};
int T, N;

int findSet(int x){
    if(SET[x] == x) return x;
    else return findSet(SET[x]);
}

int unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    if(x != y){
        COUNT[x] += COUNT[y];
        COUNT[y] = COUNT[x];
        SET[y] = x;
    }
    
    return COUNT[x];
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> T;
    
    for(int i=0; i<T; i++){
        NETWORK.clear();
        int cnt = 0;
        cin >> N;
        
        for(int k=1; k<2*N+1; k++){
            SET[k] = k;
            COUNT[k] = 1;
        }
        
        string f1, f2;
        for(int j=0; j<N; j++){
            int count = 0;
            cin >> f1 >> f2;
            if(NETWORK.find(f1) == NETWORK.end()){
                NETWORK[f1] = ++cnt;
            }
            
            if(NETWORK.find(f2) == NETWORK.end()){
                NETWORK[f2] = ++cnt;
            }
            
            cout << unionSet(NETWORK[f1], NETWORK[f2]) << "\n";
        }
    }
    
    
    return 0;
}

