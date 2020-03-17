// https://www.acmicpc.net/problem/9019
// DSLR
// Written in C++ langs
// 2020. 03. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

long long N;
int A;
int B;

bool VISITED[10001]={0,};

void bfs(){
    memset(VISITED, 0, sizeof(VISITED));
    queue<pair<int, string>> que;
    que.push(make_pair(A, ""));
    VISITED[A] = true;

    while(!que.empty()){
        int cur = que.front().first;
        string route = que.front().second;
        que.pop();

        if(cur == B){
            cout << route << "\n";
            break;
        }

        int cur_D = (cur * 2) % 10000;
        if(!VISITED[cur_D]){
            VISITED[cur_D] = true;
            que.push(make_pair(cur_D, route+'D'));
        }

        int cur_S;
        (cur == 0) ? cur_S = 9999 : cur_S = cur-1;
        if(!VISITED[cur_S]){
            VISITED[cur_S] = true;
            que.push(make_pair(cur_S, route+'S'));
        }

        int cur_L = (cur % 1000) * 10 + (cur / 1000);
        if(!VISITED[cur_L]){
            VISITED[cur_L] = true;
            que.push(make_pair(cur_L, route+'L'));
        }

        int cur_R = (cur % 10) * 1000 + (cur / 10);
        if(!VISITED[cur_R]){
            VISITED[cur_R] = true;
            que.push(make_pair(cur_R, route+'R'));
        }
    }

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> A >> B;
        bfs();
    }

    return 0;

}

