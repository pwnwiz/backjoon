// https://www.acmicpc.net/problem/2251
// 물통
// Written in C++ langs
// 2020. 03. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct BOTTLE{
    int A, B, C;
}BOTTLE;

int A, B, C;

bool VISITED_AB[201][201] = {0,};
bool VISITED_C[201] = {0,};

void bfs(){
    queue<BOTTLE> que;
    que.push({0,0,C});
    
    while(!que.empty()){
        BOTTLE cur = que.front();
        que.pop();
        
        if(VISITED_AB[cur.A][cur.B]){
            continue;
        }
        
        VISITED_AB[cur.A][cur.B] = true;
        if(cur.A == 0){
            VISITED_C[cur.C] = true;
        }
        
        if(cur.A > 0){
            // A->B
            if(cur.A + cur.B > B){
                que.push({cur.A + cur.B - B, B, cur.C});
            }
            else {
                que.push({0, cur.A + cur.B, cur.C});
            }
            // A->C
            if(cur.A + cur.C > C){
                que.push({cur.A + cur.C - C, cur.B, C});
            }
            else {
                que.push({0, cur.B, cur.A + cur.C});
            }
        }
        
        if(cur.B > 0){
            // B->A
            if(cur.A + cur.B > A){
                que.push({A, cur.A + cur.B - A, cur.C});
            }
            else {
                que.push({cur.A + cur.B, 0, cur.C});
            }
            // B->C
            if(cur.B + cur.C > C){
                que.push({cur.A, cur.B + cur.C - C, C});
            }
            else {
                que.push({cur.A, 0, cur.B + cur.C});
            }
        }
        if(cur.C > 0){
            // C->A
            if(cur.A + cur.C > A){
                que.push({A, cur.B, cur.A + cur.C - A});
            }
            else {
                que.push({cur.A + cur.C, cur.B, 0});
            }
            // C->B
            if(cur.B + cur.C > B){
                que.push({cur.A, B, cur.B + cur.C - B});
            }
            else{
                que.push({cur.A, cur.B + cur.C, 0});
            }
        }

    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B >> C;
    bfs();
    
    for(int i=0; i<=C; i++){
        if(VISITED_C[i]) cout << i << " ";
    }
    cout << "\n";
    
    return 0;
    
}

