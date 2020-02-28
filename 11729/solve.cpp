// https://www.acmicpc.net/problem/11729
// 하노이 탑 이동 순서
// Written in C++ langs
// 2020. 02. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int N;
vector<pair<int,int>> RESULT;

void hanoi(int count, int start, int help, int dest){
    if(count==1){
        RESULT.push_back(make_pair(start, dest));
        return;
    }
    
    hanoi(count-1, start, dest, help);
    RESULT.push_back(make_pair(start, dest));
    hanoi(count-1, help, start, dest);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    hanoi(N, 1, 2, 3);
    
    cout << RESULT.size() << "\n";
    
    for(int i=0; i<RESULT.size(); i++){
        cout << RESULT[i].first << " " << RESULT[i].second << "\n";
    }

    return 0;
    
}

