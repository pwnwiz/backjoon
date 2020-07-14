// https://www.acmicpc.net/problem/9935
// 문자열 폭발
// Written in C++ langs
// 2020. 07. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int N;

string input;
string bomb;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> input;
    cin >> bomb;
    
    deque<char> deq;
    
    for(auto s : input){
        deq.push_back(s);
        
        if(deq.back() == bomb[bomb.size()-1]){
            
            if(deq.size() < bomb.size()) continue;
            
            int pos = 0;
            bool flag = true;
            while(pos < bomb.size()){
                if(deq.at(deq.size()-1-pos) != bomb[bomb.size()-1-pos]){
                    flag = false;
                    break;
                }
                pos++;
            }
            
            if(flag){
                while(pos){
                    deq.pop_back();
                    pos--;
                }
            }
        }
    }
    
    if(deq.size() == 0){
        cout << "FRULA\n";
    } else {
        for(int r=0; r<deq.size(); r++){
            cout << deq.at(r);
        }
        cout << "\n";
    }
    return 0;
}

