// https://www.acmicpc.net/problem/14675
// 단절점과 단절선
// Written in C++ langs
// 2020. 08. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> EDGE;
int N, Q;

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
    
    cin >> Q;
    
    int t, k;
    for(int q=0; q<Q; q++){
        cin >> t >> k;
        
        // 단절점 : 해당 정점을 제거하였을 때 그래프가 2개 이상으로 나뉘는 경우
        if(t == 1){
            if(EDGE[k].size() >= 2) cout << "yes\n";
            else cout << "no\n";
        }
        
        // 단절선 : 해당 간선을 제거하였을 때 그래프가 2개 이상으로 나뉘는 경우
        else {
            cout << "yes\n";
        }
    }
    
    return 0;
}

