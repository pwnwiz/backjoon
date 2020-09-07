// https://www.acmicpc.net/problem/1655
// 가운데를 말해요
// Written in C++ langs
// 2020. 09. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<>> MAX_HEAP;
priority_queue<int, vector<int>, greater<>> MIN_HEAP;
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
 
        if(MAX_HEAP.empty()){
            MAX_HEAP.push(in);
        } else {
            int point = MAX_HEAP.top();
            
            if(in >= point){
                MIN_HEAP.push(in);
            } else {
                MAX_HEAP.push(in);
            }
            
            if(MIN_HEAP.size() > MAX_HEAP.size()){
                MAX_HEAP.push(MIN_HEAP.top());
                MIN_HEAP.pop();
            } else if(MAX_HEAP.size() - MIN_HEAP.size() > 1){
                MIN_HEAP.push(MAX_HEAP.top());
                MAX_HEAP.pop();
            }
        }
        
        cout << MAX_HEAP.top() << "\n";
        
    }

    return 0;
}

