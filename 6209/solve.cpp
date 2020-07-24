// https://www.acmicpc.net/problem/6209
// 제자리 멀리뛰기
// Written in C++ langs
// 2020. 07. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long D;
int N, M;

long long VALUE = 0;

void bisect(vector<long long> rocks, long long l, long long r){
    
    while(l<=r){
        long long mid = (l + r) / 2;
        
        int cnt = 0;
        int pos = 0;
        
        for(int i=1; i<rocks.size(); i++){
            if(rocks[i] - rocks[pos] < mid){
                cnt ++;
            } else {
                pos = i;
            }
        }
        
        if(cnt > M){
            r = mid - 1;
        } else {
            l = mid + 1;
            VALUE = mid;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> D >> N >> M;
    
    vector<long long> input;
    vector<long long> rocks;
    
    long long in;
    input.push_back(0);
    for(int i=0; i<N; i++){
        cin >> in;
        input.push_back(in);
    }
    input.push_back(D);
    sort(input.begin(), input.end());
    
    bisect(input, 0, D);
    cout << VALUE << "\n";
    
    return 0;
}

