// https://www.acmicpc.net/problem/2841
// 외계인의 기타 연주
// Written in C++ langs
// 2020. 07. 16.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N, P;
int COUNT = 0;

int main(){
    ios_base :: sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> P;
    
    vector<stack<int>> st(7);
    
    int line, fret;
    for(int n=0; n<N; n++){
        cin >> line >> fret;

        if(st[line].empty()){
            st[line].push(fret);
            COUNT++;
        } else {
            if(st[line].top() < fret){
                st[line].push(fret);
                COUNT++;
            } else if(st[line].top() == fret){
                continue;
            } else {
                while(!st[line].empty()){
                    if(st[line].top() > fret){
                        st[line].pop();
                        COUNT++;
                    } else {
                        break;
                    }
                }
                if(!st[line].empty() && st[line].top() == fret) continue;
                
                st[line].push(fret);
                COUNT++;
            }
        }
    }
    
    cout << COUNT << "\n";
    
    return 0;
    
}

