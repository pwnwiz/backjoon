// https://www.acmicpc.net/problem/13418
// 학교 탐방하기
// Written in C++ langs
// 2020. 08. 21.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>> EDGE;
vector<int> SET;
int N, M;

int RESULT = 0;

int findSet(int x){
    if(SET[x] == x) return x;
    return SET[x] = findSet(SET[x]);
}

void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    SET[y] = x;
}

int kruskal(){
    for(int i=0; i<SET.size(); i++){
        SET[i] = i;
    }
    
    int result = 0;
    int cnt = 0;
    
    for(auto e : EDGE){
        if(cnt == N) break;
        
        int w = get<0>(e);
        int a = get<1>(e);
        int b = get<2>(e);
        
        if(findSet(a) != findSet(b)){
            unionSet(a, b);
            result += w;
        }
    }

    result = N - result;
    return result*result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    SET.resize(N+1);
    
    int a, b, c;
    for(int i=0; i<M+1; i++){
        cin >> a >> b >> c;
        EDGE.push_back({c,a,b});
    }
    
    sort(EDGE.begin(), EDGE.end());
    RESULT = kruskal();
    
    sort(EDGE.begin(), EDGE.end(), greater<>());
    RESULT -= kruskal();
    
    cout << RESULT << "\n";
    
    return 0;
    
}

