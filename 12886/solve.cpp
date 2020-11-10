// https://www.acmicpc.net/problem/12886
// 돌 그룹
// Written in C++ langs
// 2020. 11. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int A, B, C;
bool XY[1501][1501];

bool bfs(){
    queue<tuple<int,int,int>> que;
    que.push({A,B,C});
    
    while(!que.empty()){
        int a = get<0>(que.front());
        int b = get<1>(que.front());
        int c = get<2>(que.front());
        que.pop();
        
        if(a == b && b == c && a == c) return 1;
        
        if(a!=b){
            int x = a;
            int y = b;
            if(x>y) swap(x,y);
            
            y -= x;
            x *= 2;
            
            if(x>=0 && y>=0 && x<=1500 && y<=1500 && !XY[x][y]){
                que.push({x,y,c});
                XY[x][y] = true;
            }
        }
        
        if(b!=c){
            int x = b;
            int y = c;
            if(x>y) swap(x,y);
            
            y -= x;
            x *= 2;
            
            if(x>=0 && y>=0 && x<=1500 && y<=1500 && !XY[x][y]){
                que.push({a,x,y});
                XY[x][y] = true;
            }
        }
        
        if(a!=c){
            int x = a;
            int y = c;
            if(x>y) swap(x,y);
            
            y -= x;
            x *= 2;
            
            if(x>=0 && y>=0 && x<=1500 && y<=1500 && !XY[x][y]){
                que.push({x,b,y});
                XY[x][y] = true;
            }
        }
        
    }

    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> C;
    
    bool result = bfs();
    cout << result << "\n";
    
    return 0;
}

