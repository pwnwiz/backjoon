// https://www.acmicpc.net/problem/1920
// 수 찾기
// Written in C++ langs
// 2020. 07. 20.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

vector<bool> RES;

void bisect(vector<int> &input, vector<int> &target, int tidx, int l, int r){
    if(l <= r){
        int mid = (l+r)/2;
        
        if(input[mid] == target[tidx]){
            RES[tidx] = true;
            return;
        }
        
        else if(input[mid] < target[tidx]){
            return bisect(input, target, tidx, mid+1, r);
        } else {
            return bisect(input, target, tidx, l, mid-1);
        }
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> input;
    vector<int> target;

    cin >> N;
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        input.push_back(in);
    }
    sort(input.begin(), input.end());
    
    cin >> M;
    RES.resize(M+1);
    for(int i=0; i<M; i++){
        cin >> in;
        target.push_back(in);
        bisect(input, target, i, 0, N);
    }

    for(int i=0; i<M; i++){
        cout << RES[i] << "\n";
    }
    
    return 0;
    
}

