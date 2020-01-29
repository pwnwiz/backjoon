// https://www.acmicpc.net/problem/10866
// 덱
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

deque<int> DEQUE;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string command;
    int count=0;
    int pushValue=0;
    
    cin >> count;
    
    for(int i=0; i<count; i++){
        cin >> command;
        
        if(command.compare("push_front") == 0){
            cin >> pushValue;
            DEQUE.push_front(pushValue);
        }
        
        else if(command.compare("push_back") == 0){
            cin >> pushValue;
            DEQUE.push_back(pushValue);
        }
        
        else if(command.compare("pop_front") == 0){
            if(!DEQUE.empty()){
                cout << DEQUE.front() << "\n";
                DEQUE.pop_front();
            }
            else cout << "-1\n";
        }
        
        else if(command.compare("pop_back") == 0){
            if(!DEQUE.empty()){
                cout << DEQUE.back() << "\n";
                DEQUE.pop_back();
            }
            else cout << "-1\n";
        }
        
        else if(command.compare("size") == 0){
            cout << DEQUE.size() << "\n";
        }
        
        else if(command.compare("empty") == 0){
            DEQUE.empty() ? cout << "1\n" : cout << "0\n";
        }
        
        else if(command.compare("front") == 0){
            if(!DEQUE.empty()) cout << DEQUE.front() << "\n";
            else cout << "-1\n";
        }
        
        else if(command.compare("back") == 0){
            if(!DEQUE.empty()) cout << DEQUE.back() << "\n";
            else cout << "-1\n";
        }
    }
    
    return 0;
}

