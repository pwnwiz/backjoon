// https://www.acmicpc.net/problem/10473
// 인간 대포
// Written in C++ langs
// 2020. 04. 28.
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

#define INF 99999999

using namespace std;
pair<double,double> FROM;
pair<double,double> TO;
vector<pair<double,double>> CANNON;
double walk = 5.0;
int N;

double distance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1,2));
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> FROM.first >> FROM.second;
    cin >> TO.first >> TO.second;
    cin >> N;

    double x, y;

    CANNON.push_back(FROM);
    CANNON.push_back(TO);
    for(int i=0; i<N; i++){
        cin >> x >> y;
        CANNON.push_back(make_pair(x,y));
    }

    vector<vector<pair<double,int>>> v_dist(N+2);
    double DIST[102]={0,};

    for(int i=0; i<CANNON.size(); i++){
        DIST[i] = INF;
        for(int j=0; j<CANNON.size(); j++){
            if(i==j) continue;

            double d = 0;
            if(i<2){
                d = distance(CANNON[i].first, CANNON[i].second, CANNON[j].first, CANNON[j].second)/walk;
            } else {
                double dt = distance(CANNON[i].first, CANNON[i].second, CANNON[j].first, CANNON[j].second);
                d = min(2.0 + abs(dt-50.0)/walk, dt/walk);

            }
            v_dist[i].push_back(make_pair(d,j));
        }
    }

    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<>> pq;
    DIST[0] = 0;
    pq.push(make_pair(0, 0));

    while(!pq.empty()){
        double d = pq.top().first;
        double idx = pq.top().second;
        pq.pop();

        for(auto e : v_dist[idx]){
            double w = e.first;
            int next = e.second;

            if(DIST[next] > d+w){
                DIST[next] = d+w;
                pq.push(make_pair(d+w, next));
            }
        }
    }

    cout << fixed << setprecision(6) << DIST[1] << "\n";
    return 0;

}

