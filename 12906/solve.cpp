// https://www.acmicpc.net/problem/12906
// 새로운 하노이 탑
// Written in C++ langs
// 2020. 11. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <tuple>
#include <deque>
#include <set>
using namespace std;

struct HANOI{
    string table[3];
    int count;
};

set<string> visited;
vector<deque<char>> status(3);
bool check(HANOI &hanoi){
    for(int i=0; i<hanoi.table[0].size(); i++){
        if(hanoi.table[0][i] != 'A') return false;
    }
    
    for(int i=0; i<hanoi.table[1].size(); i++){
        if(hanoi.table[1][i] != 'B') return false;
    }

    for(int i=0; i<hanoi.table[2].size(); i++){
        if(hanoi.table[2][i] != 'C') return false;
    }
    return true;
}

string getHash(HANOI &hanoi){
    string s = "";
    for(int i=0; i<3; i++){
        s += hanoi.table[i] + ';';
    }
    return s;
}

int RESULT = 987654321;
void bfs(HANOI hanoi){
    
    queue<HANOI> que;
    que.push(hanoi);
    
    while(!que.empty()){
        auto hanoi2 = que.front();
        que.pop();
        
        if(check(hanoi2)){
            cout << hanoi2.count << "\n";
            break;
        }
        
        hanoi2.count += 1;
        
        for(int i=0; i<3; i++){
            if(!hanoi2.table[i].size()) continue;

            char cur = hanoi2.table[i].back();
            hanoi2.table[i].pop_back();
            
            for(int j=0; j<3; j++){
                if(i==j) continue;
                
                hanoi2.table[j] += cur;
                auto hash = getHash(hanoi2);
                if(visited.find(hash) == visited.end()){
                    visited.insert(hash);
                    que.push(hanoi2);
                }
                hanoi2.table[j].pop_back();
            }
            hanoi2.table[i].push_back(cur);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int s;
    
    HANOI hanoi = HANOI();
    hanoi.count = 0;
    
    for(int i=0; i<3; i++){
        cin >> s;
        
        char input;
        for(int j=0; j<s; j++){
            cin >> input;
            hanoi.table[i] += input;
        }
    }

    bfs(hanoi);
    
    return 0;
}

