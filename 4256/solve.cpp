// https://www.acmicpc.net/problem/4256
// 트리
// Written in C++ langs
// 2020. 08. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int T, N;

vector<int> pre;
vector<int> in;

void makeTree(int pl, int pr, int il, int ir){
    if(pl >= pr) return;
    
    int pos = 0;
    for(int i=il; i<ir; i++){
        if(pre[pl] == in[i]) break;
        pos++;
    }
    
    makeTree(pl+1, pl+pos+1, il, il+pos);
    makeTree(pl+pos+1, pr, il+pos+1, ir);
    
    cout << pre[pl] << " ";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> N;
        
        pre.clear();
        in.clear();
        
        int input;
        for(int n=0; n<N; n++){
            cin >> input;
            pre.push_back(input);
        }
        
        for(int n=0; n<N; n++){
            cin >> input;
            in.push_back(input);
        }
        
        makeTree(0, N, 0, N);
        cout << "\n";
    }
    
    return 0;
    
}

