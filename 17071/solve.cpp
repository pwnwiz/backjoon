// https://www.acmicpc.net/problem/17071
// 숨바꼭질 5
// Written in C++ langs
// 2020. 12. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
#include <string.h>

using namespace std;

int N, K;
int VISITED[500001][2];

void bfs(){
    queue<pair<int,int>> que;
    memset(VISITED, -1, sizeof(VISITED));
    
    que.push({N,0});

    while(!que.empty()){
        int subin = que.front().first;
        int count = que.front().second;
        que.pop();
        
        if(subin >500000 || subin<0) continue;
        if(VISITED[subin][count&1] != -1) continue;
        
        if(subin-1>=0) que.push({subin-1, count+1});
        if(subin+1<=500000) que.push({subin+1, count+1});
        if(subin*2<=500000) que.push({subin*2, count+1});
        VISITED[subin][count&1] = count;
    }

    for(int i=0; i<500000; i++){
        int nn = K + (i*(i+1)/2);
        if(nn>500000) break;

        if(VISITED[nn][i&1] != -1 && VISITED[nn][i&1]<=i){
            cout << i << "\n";
            return;
        }
    }

    cout << "-1\n";

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    bfs();

    return 0;
}

