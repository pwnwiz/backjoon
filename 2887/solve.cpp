// https://www.acmicpc.net/problem/2887
// 행성 터널
// Written in C++ langs
// 2020. 04. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>
#include <math.h>

using namespace std;

vector<tuple<int, int, int, int>> PLANET;
vector<tuple<int, int, int>> DIST;

int SET[100000]={0,};
long long W;
int N;

int findSet(int x){
    if(SET[x] == x) return x;
    else return findSet(SET[x]);
}

void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    if(x<=y) SET[y] = x;
    else SET[x] = y;
}

void kruskal(){
    int cnt = 0;
    
    for(auto e : DIST){
        if(cnt == N-1) break;
        if(findSet(get<1>(e)) != findSet(get<2>(e))){
            unionSet(get<1>(e), get<2>(e));
            W += get<0>(e);
        }
    }
}

bool compareX(const tuple<int,int,int,int> &a, const tuple<int,int,int,int> &b){
    return get<0>(a) < get<0>(b);
}

bool compareY(const tuple<int,int,int,int> &a, const tuple<int,int,int,int> &b){
    return get<1>(a) < get<1>(b);
}

bool compareZ(const tuple<int,int,int,int> &a, const tuple<int,int,int,int> &b){
    return get<2>(a) < get<2>(b);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    
    int x, y, z;
    for(int i=0; i<N; i++){
        cin >> x >> y >> z;
        PLANET.push_back({x,y,z,i});
    }
    
    sort(PLANET.begin(), PLANET.end(), compareX);
    for(int i=0; i<N-1; i++){
        int d = min(abs(get<0>(PLANET[i])-get<0>(PLANET[i+1])), abs(get<1>(PLANET[i])-get<1>(PLANET[i+1])));
        d = min(d, abs(abs(get<2>(PLANET[i])-get<2>(PLANET[i+1]))));
        DIST.push_back({d,get<3>(PLANET[i]),get<3>(PLANET[i+1])});
    }
    
    sort(PLANET.begin(), PLANET.end(), compareY);
    for(int i=0; i<N-1; i++){
        int d = min(abs(get<0>(PLANET[i])-get<0>(PLANET[i+1])), abs(get<1>(PLANET[i])-get<1>(PLANET[i+1])));
        d = min(d, abs(abs(get<2>(PLANET[i])-get<2>(PLANET[i+1]))));
        DIST.push_back({d,get<3>(PLANET[i]),get<3>(PLANET[i+1])});
    }
    
    sort(PLANET.begin(), PLANET.end(), compareZ);
    for(int i=0; i<N-1; i++){
        int d = min(abs(get<0>(PLANET[i])-get<0>(PLANET[i+1])), abs(get<1>(PLANET[i])-get<1>(PLANET[i+1])));
        d = min(d, abs(abs(get<2>(PLANET[i])-get<2>(PLANET[i+1]))));
        DIST.push_back({d,get<3>(PLANET[i]),get<3>(PLANET[i+1])});
    }
    
    sort(DIST.begin(), DIST.end());

    for(int i=0; i<N; i++){
        SET[i] = i;
    }
    
    kruskal();
    
    cout << W << "\n";
 
    return 0;
}

