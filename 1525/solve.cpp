// https://www.acmicpc.net/problem/1525
// 퍼즐
// Written in C++ langs
// 2020. 03. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int VAL = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
map<int, int> PUZZLE;

void bfs(){
    queue<int> que;
    que.push(VAL);
    
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        
        if(cur == 123456789){
            cout << PUZZLE[cur] << "\n";
            return;
        }
        
        string tmp = to_string(cur);
        int idx = tmp.find('9');
        int cur_x = idx / 3;
        int cur_y = idx % 3;
        
        for(int i=0; i<4; i++){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx < 0 || nx > 2 || ny < 0 || ny > 2){
                continue;
            }
            string swapped_tmp = tmp;
            swap(swapped_tmp[idx], swapped_tmp[nx*3+ny]);
            int res = stoi(swapped_tmp);
            
            if(!PUZZLE[res]){
                PUZZLE[res] = PUZZLE[cur] + 1;
                que.push(res);
            }
        }
    }
    cout << "-1\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int no;
    for(int i=0; i<9; i++){
        cin >> no;
        if(no == 0){
            no = 9;
        }
        VAL = VAL*10 + no;
    }
    
    bfs();
    
    return 0;
}

