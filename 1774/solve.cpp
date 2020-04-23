// https://www.acmicpc.net/problem/1774
// 우주신과의 교감
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

int N, M;
vector<pair<int,int>> GOD;
vector<pair<int,int>> TUNNEL;
vector<tuple<double,int,int>> DISTANCE;
int SET[1001]={0,};
double W = 0;

int findSet(int x){
    if(SET[x] == x) return x;
    else return findSet(SET[x]);
}

void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    SET[y] = x;
}

void kruskal(){
    for(auto d : DISTANCE){
        double w = get<0>(d);
        int x = get<1>(d);
        int y = get<2>(d);
        
        if(findSet(x) != findSet(y)){
            unionSet(x,y);
            W += w;
        }
    }
}

double getDist(long long x1, long long y1, long long x2, long long y2){
    long long x = (x2-x1)*(x2-x1);
    long long y = (y2-y1)*(y2-y1);
    double val = sqrt(x+y);
    return val;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    long long x, y;
    for(int n=0; n<N; n++){
        cin >> x >> y;
        GOD.push_back(make_pair(x,y));
    }
    
    for(int i=1; i<=N; i++){
        SET[i] = i;
    }
    
    for(int m=0; m<M; m++){
        cin >> x >> y;
        TUNNEL.push_back(make_pair(x,y));
        unionSet(x,y);
    }
        
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            double dist = getDist(GOD[i].first, GOD[i].second, GOD[j].first, GOD[j].second);
            DISTANCE.push_back({dist,i+1,j+1});
        }
    }
    
    sort(DISTANCE.begin(), DISTANCE.end());

    kruskal();
    
    cout<< fixed << setprecision(2) << W << "\n";
    return 0;
}

