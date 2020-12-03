// https://www.acmicpc.net/problem/15486
// 퇴사 2
// Written in C++ langs
// 2020. 12. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <string.h>

using namespace std;

int PAY[1500051];
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<pair<int,int>> schedule;
    
    int f, t;
    for(int i=0; i<N; i++){
        cin >> f >> t;
        schedule.push_back({f,t});
    }
    
    int maxv = 0;
    for(int i=0; i<schedule.size(); i++){
        int due_date = schedule[i].first + i;
        
        maxv = max(maxv, PAY[i]);
        PAY[due_date] = max(PAY[due_date], maxv+schedule[i].second);
    }
    
    int result = 0;
    for(int i=0; i<=N; i++){
        result = max(result, PAY[i]);
    }
    
    cout << result << "\n";
    
    return 0;
}

