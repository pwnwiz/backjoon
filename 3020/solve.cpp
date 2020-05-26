// https://www.acmicpc.net/problem/3020
// 개똥벌레
// Written in C++ langs
// 2020. 05. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, H;
vector<int> OBSTACLE_DOWN;
vector<int> OBSTACLE_UP;
vector<int> TOTAL_DOWN;
vector<int> TOTAL_UP;
vector<int> RES;

void bisectDOWN(int begin, int end, int val){
    
    if(end - begin <= 1){
        if(OBSTACLE_DOWN[begin] >= val) TOTAL_DOWN.push_back(begin);
        else TOTAL_DOWN.push_back(end);
        return;
    }
    
    else{
        int mid = (begin + end) / 2;
        
        if(OBSTACLE_DOWN[mid] >= val){
            bisectDOWN(begin, mid, val);
        } else {
            bisectDOWN(mid, end, val);
        }
    }
}

void bisectUP(int begin, int end, int val){
    
    if(end - begin <=1){
        if(OBSTACLE_UP[begin] > val) TOTAL_UP.push_back(begin);
        else TOTAL_UP.push_back(end);
        return;
    }
    
    else {
        int mid = (begin + end) / 2;
        
        if(OBSTACLE_UP[mid] > val){
            bisectUP(begin, mid, val);
        } else {
            bisectUP(mid, end, val);
        }
    }
    
    
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> H;
    
    int o;
    for(int i=0; i<N; i++){
        cin >> o;
        (i%2==0) ? OBSTACLE_DOWN.push_back(o) : OBSTACLE_UP.push_back(H-o+1);
    }
    
    sort(OBSTACLE_DOWN.begin(), OBSTACLE_DOWN.end());
    sort(OBSTACLE_UP.begin(), OBSTACLE_UP.end());
    
    TOTAL_UP.push_back(0);
    
    for(int i=1; i<=H; i++){
        if(i<H) bisectDOWN(0, OBSTACLE_DOWN.size(), i);
        if(i>1) bisectUP(0, OBSTACLE_UP.size(), i);
    }
    
    TOTAL_DOWN.push_back(OBSTACLE_DOWN.size());

    RES.resize(H);
    
    for(int i=0; i<H; i++){
        RES[i] = (OBSTACLE_DOWN.size() - TOTAL_DOWN[i]) + (TOTAL_UP[i]);
    }
    
    sort(RES.begin(), RES.end());

    auto range = equal_range(RES.begin(), RES.end(), RES[0]);
    int cnt = range.second - range.first;
    
    cout << RES[0] << " " << cnt << "\n";

    return 0;
    
}

