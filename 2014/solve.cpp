// https://www.acmicpc.net/problem/2014
// 소수의 곱
// Written in C++ langs
// 2020. 05. 26.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

priority_queue<long long, vector<long long>, greater<>> PQ;
vector<long long> PRIME;
map<long long, bool> ADDED;
int K, N;
long long MAXV = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    int p;
    
    // 2,5,7 곱해질 때 사용되는 값들
    for(int k=0; k<K; k++){
        cin >> p;
        PRIME.push_back(p);
    }
    
    // 초기 큐에 2,5,7을 넣기 위함
    PQ.push(1);
    
    while(N>0){
        // N이 c가 pop될 때마다 작아짐
        long long c = PQ.top();
        PQ.pop();
        
        // 순회하면서 2,5,7을 곱해서 넣음
        for(int i=0; i<PRIME.size(); i++){
            long long x = c * PRIME[i];
            
            // N보다 크면서 큐의 마지막 값보다 큰 경우에는 넣을 이유가 없음
            if(PQ.size()>N && x>MAXV) continue;
            
            // 이미 추가된 값 또한 넣을 필요가 없음
            if(ADDED[x] == true) continue;
            
            // 최대값을 확인해주기 위해 최신화
            MAXV = max(MAXV, x);
            
            // 큐에 들어간 값인지 확인해주기 위해 true 상태로 변경
            ADDED[x] = true;
            
            // 우선순위 큐에 삽입
            PQ.push(x);
        }
        N--;
    }
    
    // N이 줄어들면서 작은 값부터 순서대로 pop되었기 때문에 top이 가장 작은 N번째 곱해진 값
    cout << PQ.top() << "\n";

    return 0;
    
}

