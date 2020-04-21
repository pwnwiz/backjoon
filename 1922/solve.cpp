// https://www.acmicpc.net/problem/1922
// 네트워크 연결
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

vector<tuple<int,int,int>> V;
int SET[1001]={0,};
int A, B;
long long RESULT = 0;

int find_set(int x){
    if(SET[x] == x) return x;
    else{
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
    for(auto cur : V){
        if(cnt == A-1) break;
        
        int w = get<0>(cur);
        int x = get<1>(cur);
        int y = get<2>(cur);
        
        if(find_set(x) != find_set(y)){
            union_set(x,y);
            RESULT += w;
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
    
    int a, b, w;
    for(int i=0; i<B; i++){
        cin >> a >> b >> w;
        V.push_back({w,a,b});
    }
    
    sort(V.begin(), V.end());
    
    kruskal();
    cout << RESULT << "\n";
    
    return 0;
}

