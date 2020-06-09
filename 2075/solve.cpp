// https://www.acmicpc.net/problem/2075
// N번째 큰 수
// Written in C++ langs
// 2020. 06. 09.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq;
    
    int in;
    for(int i=0; i<N*N; i++){
        cin >> in;
        pq.push(in);
        
        if(pq.size() == N+1) pq.pop();
    }
    
    cout << pq.top() << "\n";
    
    return 0;
    
}

