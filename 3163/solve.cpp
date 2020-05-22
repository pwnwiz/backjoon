// https://www.acmicpc.net/problem/3163
// 떨어지는 개미
// Written in C++ langs
// 2020. 05. 22.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int T;
int N, L, K;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> L >> K;
        vector<pair<int,int>> ant;
        vector<pair<int,int>> r;
        deque<int> ant_idx;
        
        int p, a;
        for(int n=0; n<N; n++){
            cin >> p >> a;
            // 양수인 경우 거리 재조정
            if(a > 0) p = L - p;
            ant.push_back(make_pair(p, a));
            ant_idx.push_back(a);
        }
        
        // 거리 순으로 정렬
        sort(ant.begin(), ant.end());
        
        // 음수인 경우 back, 양수인 경우 front에서 pop
        for(int j=0; j<N; j++){
            if(ant[j].second > 0){
                r.push_back(make_pair(ant[j].first, ant_idx.back()));
                ant_idx.pop_back();
            } else {
                r.push_back(make_pair(ant[j].first, ant_idx.front()));
                ant_idx.pop_front();
            }
        }
        
        // 우선순위를 위해 정렬 수행
        sort(r.begin(), r.end());
        cout << r[K-1].second << "\n";
    }
    
    return 0;
    
}

