// https://www.acmicpc.net/problem/9205
// 맥주 마시면서 걸어가기
// Written in C++ langs
// 2020. 04. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int T;
int C;
vector<pair<int,int>> ALLWAY;
bool DIST[102][102]={0,};

void floyd(){
    
    // i => 경유
    for(int i=0; i<C+2; i++){
        // j == 출발
        for(int j=0; j<C+2; j++){
            // k == 도착
            for(int k=0; k<C+2; k++){
                if(j==k || i==k || i==j) continue;
                if(DIST[j][i] && DIST[i][k]) DIST[j][k] = true;
            }
        }
    }
}

void print(){
    cout << "\n";
    for(int j=0; j<C+2; j++){
        for(int k=0; k<C+2; k++){
            cout << DIST[j][k] << " ";
        }
        cout << "\n";
    }
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> C;
        int a, b;
        
        for(int j=0; j<C+2; j++){
            cin >> a >> b;
            ALLWAY.push_back(make_pair(a,b));
        }

        for(int j=0; j<C+2; j++){
            for(int k=0; k<C+2; k++){
                if(j==k) continue;
                else{
                    int dist = abs(ALLWAY[k].first - ALLWAY[j].first) + abs(ALLWAY[k].second - ALLWAY[j].second);
                    if(dist<=1000){
                        DIST[j][k] = true;
                    }
                }
            }
        }
        
        floyd();
        
        DIST[0][C+1] == true ? cout << "happy\n" : cout << "sad\n";
        
        ALLWAY.clear();
        memset(DIST, false, sizeof(DIST));
    }
    
    return 0;
    
}

