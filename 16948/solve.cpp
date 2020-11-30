// https://www.acmicpc.net/problem/16948
// 데스 나이트
// Written in C++ langs
// 2020. 11. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <set>

using namespace std;

int N;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
bool visited[201][201];
int r1, c1, r2, c2;

int bfs(){
    queue<tuple<int,int,int>> que;
    que.push({r1,c1,0});
    visited[r1][c1] = true;
    
    while(!que.empty()){
        int rr = get<0>(que.front());
        int cc = get<1>(que.front());
        int cnt = get<2>(que.front());
        que.pop();
        
        if(rr==r2 && cc==c2){
            return cnt;
        }
        
        for(int i=0; i<6; i++){
            int rrr = rr + dx[i];
            int ccc = cc + dy[i];
            
            if(rrr<0 || ccc<0 || rrr>=N || ccc>=N) continue;
            if(visited[rrr][ccc]) continue;
            
            que.push({rrr,ccc,cnt+1});
            visited[rrr][ccc] = true;
        }
    }
    return -1;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;
    
    int result = bfs();
    cout << result << "\n";
    
    return 0;
}

