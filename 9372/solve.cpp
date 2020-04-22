// https://www.acmicpc.net/problem/9372
// 상근이의 여행
// Written in C++ langs
// 2020. 04. 22.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int T, N, M;
vector<pair<int,int>> PLANE;
int SET[1001]={0,};

int findSet(int x){
    if(SET[x] == x) return x;
    else return findSet(SET[x]);
}

void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    SET[y] = x;
}

int kruskal(){
    int cnt = 0;
    
    for(int i=1; i<=N; i++){
        SET[i] = i;
    }
    
    for(auto p : PLANE){
        if(findSet(p.first) != findSet(p.second)){
            unionSet(p.first, p.second);
            cnt++;
        }
    }
    
    return cnt;
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> M;
    
        int a,b;
        for(int j=0; j<M; j++){
            cin >> a >> b;
            if(a<b) PLANE.push_back(make_pair(a,b));
            else PLANE.push_back(make_pair(b,a));
        }
        
        cout << kruskal() << "\n";
        PLANE.clear();
        
    }
    
}

