// https://www.acmicpc.net/problem/14395
// 4연산
// Written in C++ langs
// 2020. 11. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

long long S, T;
set<long long> SETT;

void bfs(long long s, long long t){
    queue<pair<long long,string>> que;
    que.push({s,""});
    SETT.insert(s);
    
    while(!que.empty()){
        
        queue<pair<long long, string>> que2;
        
        while(!que.empty()){
            long long cur = que.front().first;
            string exp = que.front().second;
            que.pop();
            
            if(cur == t){
                if(exp.length() == 0){
                    cout << "0\n";
                }else {
                    cout << exp << "\n";
                }
                return;
            }
            
            long long mul = cur * cur;
            if(mul>=1 && SETT.find(mul) == SETT.end()){
                SETT.insert(mul);
                que2.push({mul, exp+"*"});
            }
            
            long long plus = cur + cur;
            if(plus>=1 && SETT.find(plus) == SETT.end()){
                SETT.insert(plus);
                que2.push({plus, exp+"+"});
            }
        
            long long minus = cur - cur;
            if(minus>=1 && SETT.find(minus) == SETT.end()){
                SETT.insert(minus);
                que2.push({minus, exp+"-"});
            }
            
            if(cur == 0) continue;
            long long div = cur / cur;
            if(div>=1 && SETT.find(div) == SETT.end()){
                SETT.insert(div);
                que2.push({div, exp+"/"});
            }
        }
        
        que = que2;
    }
    
    cout << "-1\n";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> S >> T;
    
    bfs(S, T);
    
    return 0;
}

