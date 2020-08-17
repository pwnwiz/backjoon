// https://www.acmicpc.net/problem/1034
// 램프
// Written in C++ langs
// 2020. 08. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

char MAP[50][50];
int N, M, K;

int RESULT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    
    cin >> K;
    
    // K가 짝수인 경우
    if(K%2){
        priority_queue<int, vector<int>, less<>> pq;
        pq.push(0);
        
        // 0의 개수를 세어서 적합한지 확인
        for(int i=0; i<N; i++){
            int zero = 0;
            for(int j=0; j<M; j++){
                if(MAP[i][j] == '0') zero++;
            }
            
            // 개수를 카운트해서 우선순위 큐에 넣어줌
            if(zero%2 && zero<=K){
                int tc = 0;
                for(int j=0; j<N; j++){
                    bool flag = true;
                    for(int k=0; k<M; k++){
                        if(MAP[i][k] != MAP[j][k]){
                            flag = false;
                            break;
                        }
                    }
                    
                    if(flag) tc++;
                }
                
                pq.push(tc);
            }
        }
        
        cout << pq.top() << "\n";
        
    }
    
    // K가 홀수인 경우
    else {
        priority_queue<int, vector<int>, less<>> pq;
        pq.push(0);
        
        for(int i=0; i<N; i++){
            int zero = 0;
            for(int j=0; j<M; j++){
                if(MAP[i][j] == '0') zero++;
            }
            
            if(!(zero%2) && zero<=K){
                int tc = 0;
                for(int j=0; j<N; j++){
                    bool flag = true;
                    for(int k=0; k<M; k++){
                        if(MAP[i][k] != MAP[j][k]){
                            flag = false;
                            break;
                        }
                    }
                    
                    if(flag) tc++;
                }
                
                pq.push(tc);
            }
        }
        
        cout << pq.top() << "\n";
    }
    
    
    
    return 0;
}

