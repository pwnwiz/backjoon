// https://www.acmicpc.net/problem/1021
// 회전하는 큐
// Written in C++ langs
// 2020. 05. 12.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <bitset>

using namespace std;

int N, M;
int TOTAL = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;
    
    deque<int> dq;
    
    for(int i=1; i<=M; i++){
        dq.push_back(i);
    }
    
    int idx;
    for(int i=0; i<N; i++){
        cin >> idx;
        
        auto cur = find(dq.begin(), dq.end(), idx);
        int dist_front = distance(dq.begin(), cur);
        int dist_end = distance(cur, dq.end()) ;

        if(dist_front <= dist_end){
            while(dist_front>0){
                int pop = dq.front();
                dq.pop_front();
                dq.push_back(pop);
                TOTAL++;
                dist_front--;
            }
            dq.pop_front();
        } else {
            while(dist_end>0){
                int pop = dq.back();
                dq.pop_back();
                dq.push_front(pop);
                TOTAL++;
                dist_end--;
            }
            dq.pop_front();
        }
    }
    
    cout << TOTAL << "\n";
    
    return 0;
    
}

