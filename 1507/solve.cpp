// https://www.acmicpc.net/problem/1507
// 궁금한 민호
// Written in C++ langs
// 2020. 06. 19.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int MAP[20][20];
bool NEWMAP[20][20];

bool kruskal(){
    // 경유
    for(int i=0; i<N; i++){
        // 시작
        for(int j=0; j<N; j++){
            // 도착
            for(int k=0; k<N; k++){
                if(i==j || j==k || i==k) continue;
                // 만약 경유지를 통해 연결된 경우에 해당 정보를 지워줄 수 있음
                if(MAP[j][k] == MAP[j][i] + MAP[i][k]){
                    NEWMAP[j][k] = 1;
                }
                // 경유지를 통해 연결된 경우보다 가지고 있는 값이 크다면 최단 경로가 아님
                else if(MAP[j][k] > MAP[j][i] + MAP[i][k]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> MAP[i][j];
        }
    }
    
    int total = 0;
    
    bool res = kruskal();
    
    if(!res){
        cout << "-1\n";
    } else {
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                if(!NEWMAP[i][j]){
                    total += MAP[i][j];
                }
            }
        }
        cout << total << "\n";
    }
    return 0;
}

