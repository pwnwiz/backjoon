// https://www.acmicpc.net/problem/2831
// 댄스 파티
// Written in C++ langs
// 2020. 04. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> PLUS_MEN;
priority_queue<int, vector<int>, greater<int>> MINUS_MEN;
priority_queue<int, vector<int>, greater<int>> PLUS_WOMEN;
priority_queue<int, vector<int>, greater<int>> MINUS_WOMEN;
int N;

int COUNT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int h;
    for(int i=0; i<N; i++){
        cin >> h;
        if(h<0){
            MINUS_MEN.push(abs(h));
        }
        else{
            PLUS_MEN.push(h);
        }
    }
    
    for(int i=0; i<N; i++){
        cin >> h;
        if(h<0){
            MINUS_WOMEN.push(abs(h));
        }
        else{
            PLUS_WOMEN.push(h);
        }
    }
    
    while(!PLUS_MEN.empty() && !MINUS_WOMEN.empty()){
        int cur_woman = MINUS_WOMEN.top();
        int cur_man = PLUS_MEN.top();
        MINUS_WOMEN.pop();
        
        if(cur_man < cur_woman){
            PLUS_MEN.pop();
            COUNT++;
        }
    }
    
    while(!PLUS_WOMEN.empty() && !MINUS_MEN.empty()){
        int cur_man = MINUS_MEN.top();
        int cur_woman = PLUS_WOMEN.top();
        MINUS_MEN.pop();
        
        if(cur_woman < cur_man){
            PLUS_WOMEN.pop();
            COUNT++;
        }
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

