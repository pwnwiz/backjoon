// https://www.acmicpc.net/problem/1931
// 회의실배정
// Written in C++ langs
// 2020. 03. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> SCHEDULE;
int SELECTED = 0;
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int begin, end;
    for(int i=0; i<N; i++){
        cin >> begin >> end;
        SCHEDULE.push_back(make_pair(end, begin));
    }
    
    sort(SCHEDULE.begin(), SCHEDULE.end());
    
    int earliest = 0;
    
    for(int i=0; i<SCHEDULE.size(); i++){
        int meetingBegin = SCHEDULE[i].second;
        int meetingEnd = SCHEDULE[i].first;
        
        if(meetingBegin >= earliest){
            earliest = meetingEnd;
            SELECTED++;
        }
    }
    
    cout << SELECTED << "\n";
    
    return 0;
}

