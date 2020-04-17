// https://www.acmicpc.net/problem/12761
// 돌다리
// Written in C++ langs
// 2020. 04. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int A, B, FROM, TO;
bool VISITED[3000001] = {0,};
int COUNT = 0;

void bfs(){
    queue<int> que;
    que.push(FROM);
    VISITED[FROM] = true;
    
    while(!que.empty()){
        queue<int> que2;
        while(!que.empty()){
            vector<int> choice;
            int x = que.front();
            que.pop();
            
            if(x == TO){
                cout << COUNT << "\n";
                return;
            }
            
            choice.push_back(x+1);
            choice.push_back(x-1);
            choice.push_back(x+A);
            choice.push_back(x-A);
            choice.push_back(x+B);
            choice.push_back(x-B);
            choice.push_back(x*A);
            choice.push_back(x*B);
            
            for(int i=0; i<choice.size(); i++){
                int cur = choice[i];
                if(!VISITED[cur] && cur<=100000 && cur>=0){
                    VISITED[cur] = true;
                    que2.push(cur);
                }
            }
        }
        que = que2;
        COUNT++;
        
    }
    
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> FROM >> TO;
    
    bfs();
    
    
    return 0;
}

