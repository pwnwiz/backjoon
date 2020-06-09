// https://www.acmicpc.net/problem/2157
// 여행
// Written in C++ langs
// 2020. 06. 09.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>

#define INF 999999999

using namespace std;

int N, M, K;
int DIST[300][300];
int DP[300][300];


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    int a, b, c;
    for(int i=0; i<K; i++){
        cin >> a >> b >> c;
        DIST[a-1][b-1] = max(DIST[a-1][b-1], c);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            DP[i][j] = -INF;
        }
    }
    
    DP[0][0] = 0;
    for(int from=0; from<N; from++){
        for(int to=from+1; to<N; to++){
            for(int visit_cnt=1; visit_cnt<M; visit_cnt++){
                if(DIST[from][to] && DP[from][visit_cnt-1]>=0){
                    DP[to][visit_cnt] = max(DP[to][visit_cnt], DP[from][visit_cnt-1]+DIST[from][to]);
                }
            }
        }
    }
    

    int result = 0;
    for(int i=0; i<M; i++){
        result = max(result, DP[N-1][i]);
    }

    cout << result << "\n";

    return 0;
    
}

