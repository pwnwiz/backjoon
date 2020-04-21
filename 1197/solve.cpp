// https://www.acmicpc.net/problem/1197
// 최소 스패닝 트리
// Written in C++ langs
// 2020. 04. 21.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

vector<tuple<int,int,int>> v;
int SET[10002]={0,};
int A, B;
long long RESULT = 0;


int find_set(int x){
    if(SET[x] == x) return x;
    else {
        return find_set(SET[x]);
    }
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    SET[y] = x;
}

void kruskal(){
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        if(cnt == A-1) break;

        int w = get<0>(v[i]);
        int x = get<1>(v[i]);
        int y = get<2>(v[i]);
        if(find_set(x) != find_set(y)){
            RESULT += w;
            union_set(x, y);
            cnt++;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B;
    
    for(int i=0; i<A; i++){
        SET[i] = i;
    }

    int from, to, weight;
    for(int i=0; i<B; i++){
        cin >> from >> to >> weight;
        v.push_back({weight, from, to});
    }
    
    sort(v.begin(), v.end());
    
    kruskal();
    
    cout << RESULT << "\n";
    
    return 0;
}

