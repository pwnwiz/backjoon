// https://www.acmicpc.net/problem/2263
// 트리의 순회
// Written in C++ langs
// 2020. 03. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

int N;
int POST[100000]={0,};
int IN[100000]={0,};
int LOC[100000]={0,};

using namespace std;

void dc(int in_left, int in_right, int post_left, int post_right){
    if(in_left>in_right || post_left>post_right){
        return;
    }
    
    int root = POST[post_right];
    cout << root << " ";
    
    int wall = post_left + (LOC[root] - in_left);
    dc(in_left, LOC[root]-1, post_left, wall-1);
    dc(LOC[root]+1, in_right, wall, post_right-1);
}

void getIndexOfIN(){
    for(int i=0; i<N; i++){
        LOC[IN[i]] = i;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> IN[i];
    }
    
    for(int i=0; i<N; i++){
        cin >> POST[i];
    }
    
    getIndexOfIN();
    dc(0, N-1, 0, N-1);
    cout << "\n";
    return 0;
    
}

