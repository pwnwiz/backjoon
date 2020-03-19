// https://www.acmicpc.net/problem/5014
// 스타트링크
// Written in C++ langs
// 2020. 03. 19.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int COUNT;

int TOTAL_FLOOR, START, END, UP, DOWN;
bool VISITED[1000001]={0,};

void bfs(){
    queue<int> que;
    que.push(START);
    VISITED[START] = true;
    
    int count = 0;
    while(!que.empty()){
        queue<int> que2;
        while(!que.empty()){
            int cur_floor = que.front();
            que.pop();
            
            if(cur_floor == END){
                cout << count << "\n";
                return;
            }
            
            int after_UP = cur_floor + UP;
            if(after_UP <= TOTAL_FLOOR){
                if(!VISITED[after_UP]){
                    VISITED[after_UP] = true;
                    que2.push(after_UP);
                }
            }
            
            int after_DOWN = cur_floor - DOWN;
            if(after_DOWN >= 1){
                if(!VISITED[after_DOWN]){
                    VISITED[after_DOWN] = true;
                    que2.push(after_DOWN);
                }
            }
        }
        que = que2;
        count ++;
    }
    
    cout << "use the stairs\n";

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> TOTAL_FLOOR >> START >> END >> UP >> DOWN;
    if((START > END && !DOWN) || (START < END && !UP)){
        cout << "use the stairs\n";
        return 0;
    }
    
    bfs();
    
    return 0;
    
}

