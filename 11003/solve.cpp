// https://www.acmicpc.net/problem/11003
// 최솟값 찾기
// Written in C++ langs
// 2020. 05. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <deque>

using namespace std;

int N, L;
vector<long long> INPUT;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;

    int c;
    for(int i=0; i<N; i++){
        cin >> c;
        INPUT.push_back(c);
    }

    deque<pair<int,int>> deq;
    deq.push_back(make_pair(0, INPUT[0]));
    
    int l = 0-L+1;
    int r = 0;
    for(int i=0; i<N; i++){
        
        // 범위를 초과할 경우
        while (!deq.empty() && deq.front().first<l){
            deq.pop_front();
        }
        
        // 범위 안에 속하는 경우 가장 최솟값을 front에 유지하기 위하여 back부터 pop 수행
        while(!deq.empty() && deq.back().second > INPUT[r]){
            deq.pop_back();
        }
        
        // 현재 위치의 값을 넣어줌
        // 이로 인하여 덱의 최대 크기는 L을 유지
        deq.push_back(make_pair(r,INPUT[r]));
        cout << deq.front().second << " ";
        
        l++;
        r++;
        
    }
    cout << "\n";
    
    return 0;
}

