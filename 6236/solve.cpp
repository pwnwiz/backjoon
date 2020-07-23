// https://www.acmicpc.net/problem/6236
// 용돈 관리
// Written in C++ langs
// 2020. 07. 23.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int MV = 0;

long long K = 100000*10000;
long long RES = 100001;

void bisect(vector<int> &input, long long l, long long r){
    
    while(l <= r){
        long long mid = (l + r)/2;
        
        long long cur = 0;
        long long cnt = 0;
        for(auto in : input){
            if(cur < in){
                cur = mid;
                cnt++;
            }
            cur -= in;
        }
        
        if(cnt > M){
            l = mid + 1;
        } else {
            if(MV <= mid) RES = min(RES, mid);
            r = mid - 1;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    vector<int> input;
    
    int in;
    int minv = 0;
    int maxv = 0;
    for(int i=0; i<N; i++){
        cin >> in;
        input.push_back(in);
        minv = max(minv, in);
        MV = max(MV, in);
        maxv += in;
    }
    
    bisect(input, minv, maxv);
    cout << RES << "\n";
    
    return 0;
}

