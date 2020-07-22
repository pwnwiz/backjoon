// https://www.acmicpc.net/problem/2792
// 보석 상자
// Written in C++ langs
// 2020. 07. 22.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long N, M;

long long jealous = 987654321;

// 보석의 개수를 쪼개면서 가장 작은 가능성을 찾기 위한 이분탐색
void bisect(vector<int> in, long l, long r){
    int cnt;
    
    while(l <= r){
        cnt = 0;

        long long mid = (l + r) / 2;
        
        // mid값을 기준으로 인원의 수를 카운트
        for(auto input : in){
            cnt += input / mid;
            if(input % mid) cnt++;
        }
        
        // 인원의 수가 N보다 적을 경우 더 작은 보석을 배분받을 가능성이 존재함
        // 그 외에는 인당 보석의 수를 늘려야 함
        if(cnt <= N){
            jealous = min(jealous, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    vector<int> in;
    int maxv = 0;
    
    int input;
    for(int i=0; i<M; i++){
        cin >> input;
        in.push_back(input);
        maxv = max(maxv, input);
    }
    
    bisect(in, 1, maxv);
    
    cout << jealous << "\n";
    
}

