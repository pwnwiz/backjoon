// https://www.acmicpc.net/problem/10775
// 공항
// Written in C++ langs
// 2020. 06. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int G, P;

int find(vector<int> &set, int x){
    if(set[x] == x){
        return x;
    } else {
        return set[x] = find(set, set[x]);
    }
}

void Union(vector<int> &set, int x, int y){
    x = find(set, x);
    y = find(set, y);
    set[x] = y;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> G;
    cin >> P;
    
    vector<int> disjoint_set;
    disjoint_set.resize(G+1);
    
    for(int i=0; i<disjoint_set.size(); i++){
        disjoint_set[i] = i;
    }
    
    int g;
    int cnt = 0;
    for(int p=0; p<P; p++){
        
        // 문제의 조건을 봤을 때 4라는 범위가 주어지면
        // 4에 docking을 하는 것이 가장 효율적임
        // 결국 마지막에는 1에 docking을 하게 될 것이고
        // merge를 통해 dock, dock-1로 0을 가지게 되면 더 이상 도킹이 불가능
        cin >> g;
        int dock = find(disjoint_set, g);
        
        if(dock <= 0) break;
        Union(disjoint_set, dock, dock-1);
        cnt++;
    }
    
    cout << cnt << "\n";

    return 0;
    
}

