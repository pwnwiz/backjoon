// https://www.acmicpc.net/problem/1963
// 소수 경로
// Written in C++ langs
// 2020. 03. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int N;
int FROM, TO;

bool isPrime(int num) {
    if (num == 1) return false;
    for (int i = 2; i * i <= num; i++)
        if (!(num % i)) return false;
    return true;
}

int getDigit(int num, int digit){
    return (num / (int)pow(10,3-digit)) % 10;
}

int getValue(int num, int digitval, int newval, int digit){
    return num - (digitval * (int)pow(10,3-digit)) + (newval * (int)pow(10,3-digit));
}

void bfs(){
    bool VISITED[10000] = {0,};
    queue<int> que;
    int count = 0;
    que.push(FROM);
    
    while(!que.empty()){
        queue<int> que2;
        
        while(!que.empty()){
            int cur = que.front();
            VISITED[cur] = true;
            que.pop();
            
            if(cur == TO){
                cout << count << "\n";
                return;
            }

            for(int i=0; i<4; i++){
                for(int j=0; j<=9; j++){
                    if(j==0 && i==0){
                        continue;
                    }
    
                    int tmp = getValue(cur, getDigit(cur, i), j, i);
                    
                    if(isPrime(tmp) && !VISITED[tmp]){
                        que2.push(tmp);
                    }
                }
            }
        }
        que = que2;
        count++;
    }
    cout << "Impossible" << "\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> FROM;
        cin >> TO;
        bfs();
    }
    
    return 0;
    
}

