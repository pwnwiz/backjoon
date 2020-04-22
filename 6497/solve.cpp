// https://www.acmicpc.net/problem/6497
// 전력난
// Written in C++ langs
// 2020. 04. 22.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>
#include <math.h>

using namespace std;

int N, M;
int SET[200001] = {0,};
vector<tuple<int,int,int>> ROAD;
long long TOTAL = 0;
long long DIST = 0;

int findSET(int x){
    if(SET[x] == x) return x;
    else return findSET(SET[x]);
}

void UnionSET(int x, int y){
    x = findSET(x);
    y = findSET(y);
    SET[y] = x;
}

void kruskal(){
    for(int i=0; i<=M; i++){
        SET[i] = i;
    }
    
    int cnt = 0;
    for(auto r : ROAD){
        int w = get<0>(r);
        int x = get<1>(r);
        int y = get<2>(r);
        if(findSET(x) != findSET(y)){
            DIST += w;
            UnionSET(x,y);
            cnt++;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    do {
        TOTAL = 0;
        DIST = 0;
        ROAD.clear();
        
        cin >> N >> M;
        
        if(N==0 && M==0) break;
        
        int a, b, c;
        for(int i=0; i<M; i++){
            cin >> a >> b >> c;
            TOTAL += c;
            ROAD.push_back({c,a,b});
        }

        sort(ROAD.begin(), ROAD.end());
        
        kruskal();
        
        cout << TOTAL - DIST << "\n";
    } while(N!=0 && M!=0);
}

