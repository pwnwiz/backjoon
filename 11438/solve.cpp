// https://www.acmicpc.net/problem/11438
// LCA 2
// Written in C++ langs
// 2020. 06. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

int N, M;
vector<vector<int>> EDGE;
bool VISITED[100001];
int DEPTH[100001];

// ceil(log2(100000))
// 16.609640474436812
#define height 17

int PARENT[100001][height+1];

// 첫 부모에 대한 정보와 깊이를 초기화 하기 위해 사용됨
void bfs(int s, int depth){
    VISITED[s] = true;
    DEPTH[s] = depth;
    
    for(auto e : EDGE[s]){
        if(!VISITED[e]){
            PARENT[e][0] = s;
            bfs(e, depth+1);
        }
    }
}

// 부모에 대한 부분을 채우기 위해서 호출 됨
// 예를 들어 다음과 같은 테이블이 존재한다면
// v   1 2 3 4 5
// k=1 4 3 5 2 1
// k=2 2 5 1 3 4
// k가 2일 경우 1번의 값은 k=1 일 때의 1번 값인 4의 값인 2가 됨
// k는 자신의 몇 세대 위의 조상인지를 나타내는 지표가 됨
void fillParent(){
    for(int i=1; i<=height; i++){
        for(int j=1; j<=N; j++){
            PARENT[j][i] = PARENT[PARENT[j][i-1]][i-1];
        }
    }
}

int lca(int a, int b){
    if(DEPTH[a] > DEPTH[b]){
        swap(a,b);
    }
    
    // 높이를 똑같이 맞추주기 위해서 depth를 지속적으로 비교함
    // depth의 차이가 1<<i 와 같아지면 depth를 맞춰주기 위해서 b의 값을 최신화
    for(int i=height; i>=0; i--){
        if(DEPTH[b] - DEPTH[a] >= (1<<i)){
            b = PARENT[b][i];
        }
    }
        
    // 같은 경우 a 본인이 공통 조상이 됨
    if(a == b){
        return a;
    }
    
    // 각각의 조상을 찾은 뒤 조상이 다를 경우 depth를 한 단계 위로 올림
    // 결론 적으로 공통 조상을 가리키게 됨
    for(int i=height; i>=0; i--){
        if(PARENT[a][i] != PARENT[b][i]){
            a = PARENT[a][i];
            b = PARENT[b][i];
        }
    }
    
    // 같은 조상을 가지고 있으므로 바로 위 조상에 대한 정보가 공통조상
    return PARENT[a][0];
    
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    EDGE.resize(N+1);
    
    int a, b;
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        EDGE[a].push_back(b);
        EDGE[b].push_back(a);
    }
    
    bfs(1, 0);
            
    fillParent();
    
    cin >> M;
    for(int m=0; m<M; m++){
        cin >> a >> b;
        cout << lca(a,b) << "\n";
    }
    
    return 0;
    
}

