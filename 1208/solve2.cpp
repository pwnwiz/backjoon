// https://www.acmicpc.net/problem/1208
// 부분수열의 합 2
// Written in C++ langs
// 2020. 03. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, S;
int BEGIN, END;
int HALF;

vector<int> SEQUENCE;
vector<int> LEFT;
vector<int> RIGHT;

long long COUNT=0;

bool compare(int A, int B){
    return A>B;
}

void dfs(int idx, int sum, int end){
    if(idx == end){
        if(end == HALF){
            LEFT.push_back(sum);
        }
        else{
            RIGHT.push_back(sum);
        }
        return;
    }
    dfs(idx+1, sum, end);
    dfs(idx+1, sum+SEQUENCE[idx], end);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> S;
    
    int tmp;
    for(int i=0; i<N; i++){
        cin >> tmp;
        SEQUENCE.push_back(tmp);
    }
    
    HALF = SEQUENCE.size()/2;
    
    dfs(0, 0, HALF);
    dfs(HALF, 0, N);
    
    sort(RIGHT.begin(), RIGHT.end());
    
    BEGIN=0;
    END=0;
  
    for(int left_value : LEFT){
        auto range = equal_range(RIGHT.begin(), RIGHT.end(), S - left_value);
        COUNT += range.second - range.first;
    }

    (S == 0) ? cout << COUNT-1 << "\n" : cout << COUNT << "\n" ;

    return 0;
    
}

