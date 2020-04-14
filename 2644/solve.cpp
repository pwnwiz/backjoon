// https://www.acmicpc.net/problem/2644
// 촌수계산
// Written in C++ langs
// 2020. 04. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>

using namespace std;

int T1;
int A, B;
int T2;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool MAP[102][102]={0,};
bool VISITED[102]={0,};

queue<int> QUE;
void bfs(){
    int cnt = 0;
    VISITED[A] = true;
    QUE.push(A);

    while(!QUE.empty()){
        cnt++;
        queue<int> que2;
        while(!QUE.empty()){
            int cur = QUE.front();
            QUE.pop();

            if(cur == B){
                cout << cnt-1 << "\n";
                return;
            }
            
            for(int i=1; i<=T1; i++){
                if(MAP[cur][i] && !VISITED[i]){
                    VISITED[i] = true;
                    que2.push(i);
                }
            }
        }
        QUE=que2;
    }
    
    cout << "-1\n";
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T1 >> A >> B >> T2;
    
    int a, b;
    for(int i=0; i<T2; i++){
        cin >> a >> b;
        MAP[a][b] = true;
        MAP[b][a] = true;
    }
    
    bfs();

    return 0;
    
}

