// https://www.acmicpc.net/problem/1966
// 프린터 큐
// Written in C++ langs
// 2020. 07. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int T, N, M;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> N >> M;
        
        deque<pair<int,int>> deq;
        
        int in;
        for(int n=0; n<N; n++){
            cin >> in;
            deq.push_back(make_pair(in, n));
        }
        
        int pos = 0;
        while(!deq.empty()){
            int maxv = 0;
            
            for(auto d : deq){
                maxv = max(maxv, d.first);
            }
            
            if(deq.front().first != maxv){
                deq.push_back(deq.front());
                deq.pop_front();
            }
            
            else {
                pos++;
                if(deq.front().second == M){
                    cout << pos << "\n";
                    break;
                }
                deq.pop_front();
            }
        }
    }
    
    return 0;
}

