// https://www.acmicpc.net/problem/1477
// 휴게소 세우기
// Written in C++ langs
// 2020. 07. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, L;

// 사이의 거리를 기준으로 이분 탐색을 진행
int bisect(vector<int> &dist, int l, int r){
    
    while(l<=r){
        int mid = (l + r) / 2;
    
        int store = 0;
        for(auto d: dist){
            store += d / mid;
            
            // 이미 편의점이 존재할 경우 세운 횟수를 하나 줄여줄 필요가 있음
            if(d % mid == 0) store -= 1;
        }
        
        // 편의점의 개수가 많을 경우에는 간격을 넓혀야 됨
        // 반대로 편의점의 개수가 모자랄 경우에는 간격을 좁혀야 됨
        if(store > M){
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return l;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> L;
    
    vector<int> input;
    vector<int> dist;
    
    input.push_back(0);
    
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        input.push_back(in);
    }
    
    input.push_back(L);
    sort(input.begin(), input.end());
    
    for(int i=1; i<input.size(); i++){
        dist.push_back(input[i] - input[i-1]);
    }
    sort(dist.begin(), dist.end(), greater<>());
    
    cout << bisect(dist, 1, L) << "\n";
    
    return 0;
    
}

