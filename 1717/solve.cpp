// https://www.acmicpc.net/problem/1717
// 집합의 표현
// Written in C++ langs
// 2020. 06. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int M;

int SET[1000001];

int Find(int x){
    if(SET[x] == x) return x;
    else return SET[x] = Find(SET[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);

    if(x == y) return;
    
    SET[y] = x;
}

bool IsInSet(int x, int y){
    return Find(x) == Find(y);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=0; i<=N; i++){
        SET[i] = i;
    }
    
    int c, a, b;
    for(int m=0; m<M; m++){
        cin >> c >> a >> b;
        
        if(c==0){
            Union(a,b);
        } else if (c==1){
            IsInSet(a,b) ? cout << "YES\n" : cout << "NO\n";
        }
    }
    
    return 0;
    
}

