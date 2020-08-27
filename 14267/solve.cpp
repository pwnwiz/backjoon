// https://www.acmicpc.net/problem/14267
// 내리 칭찬
// Written in C++ langs
// 2020. 08. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> USER;
vector<int> COMPLIMENT;
vector<bool> VISITED;
vector<int> QUERY;
int N, M;

void compliment(int pos, int val){
    VISITED[pos] = true;
    COMPLIMENT[pos] += val;
    
    for(auto next : USER[pos]){
        if(VISITED[next]) continue;
        
        compliment(next, val+QUERY[next]);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    USER.resize(N+1);
    COMPLIMENT.resize(N+1, 0);
    VISITED.resize(N+1, false);
    QUERY.resize(N+1, 0);
    
    int root = -1;
    
    int parent;
    for(int n=1; n<=N; n++){
        cin >> parent;
        if(parent == -1){
            root = n;
        } else {
            USER[parent].push_back(n);
        }
    }
    
    int a, b;
    for(int m=1; m<=M; m++){
        cin >> a >> b;
        QUERY[a] += b;
    }
    
    compliment(root, 0);
    
    for(int n=1; n<=N; n++){
        cout << COMPLIMENT[n] << " ";
    }
    cout << "\n";
    
    
    return 0;
}

