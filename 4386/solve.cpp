// https://www.acmicpc.net/problem/4386
// 별자리 만들기
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

int N;
vector<pair<double,double>> STAR;
vector<vector<pair<double,int>>> DIST(101);
priority_queue<pair<double,int>, vector<pair<double,int>>, greater<>> PQ;
bool VISITED[101]={0,};
double RESULT = 0;

void prim(int c){
    VISITED[c] = true;
    
    for(auto s : DIST[c]){
        if(!VISITED[s.second]){
            PQ.push(s);
        }
    }
    
    while(!PQ.empty()){
        auto w = PQ.top();
        PQ.pop();
        
        if(!VISITED[w.second]){
            RESULT += w.first;
            prim(w.second);
            return;
        }
    }
}

double calc_dist(double x1, double y1, double x2, double y2){
    double x = (x2-x1) * (x2-x1);
    double y = (y2-y1) * (y2-y1);
    double d = sqrt(x+y);
    return d;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    double a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        STAR.push_back(make_pair(a,b));
    }
    
    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            double d = calc_dist(STAR[i].first, STAR[i].second, STAR[j].first, STAR[j].second);
            DIST[i].push_back(make_pair(d,j));
            DIST[j].push_back(make_pair(d,i));
        }
    }
    
    prim(0);
    
    cout << RESULT << "\n";
    
}

