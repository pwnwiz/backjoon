// https://www.acmicpc.net/problem/14501
// 퇴사
// Written in C++ langs
// 2020. 07. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> INFO;
vector<int> DP;
int N;

void backtracking(int day){
    if(day > N) return;
    
    int duration = INFO[day-1].first;
    int point = INFO[day-1].second;

    if(duration + day <= N+1){
        int maxv = 0;
        for(int x=1; x<day; x++){
            maxv = max(maxv, DP[x]);
        }
        DP[day] = max(DP[day], maxv);
        DP[day + duration] = max(DP[day + duration], DP[day]+point);
    }
    
    backtracking(day+1);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> N;
    DP.resize(N+2);
    
    int a, b;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        INFO.push_back(make_pair(a,b));
    }
    
    backtracking(1);
    
    int res = 0;
    for(auto d : DP){
        res = max(res, d);
    }
    
    cout << res << "\n";
    
    return 0;
}

