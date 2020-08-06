// https://www.acmicpc.net/problem/2230
// 수 고르기
// Written in C++ langs
// 2020. 08. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

long long N, M;

vector<long long> ARR;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    long long in;
    for(int i=0; i<N; i++){
        cin >> in;
        ARR.push_back(in);
    }
    
    sort(ARR.begin(), ARR.end());
    
    int l = 0;
    int r = l+1;
    
    long long val = LLONG_MAX;
    while(r<ARR.size() && l<ARR.size()){
        if(ARR[r] - ARR[l] >= M){
            val = min(val, ARR[r]-ARR[l]);
            l++;
        }
        else {
            r++;
        }
    }
    
    cout << val << "\n";
    
    return 0;
    
}

