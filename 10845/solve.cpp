// https://www.acmicpc.net/problem/10845
// 큐
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

queue<int> QUEUE;

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
        
        if(command.compare("push") == 0){
            cin >> pushValue;
            QUEUE.push(pushValue);
        }
        
        else if(command.compare("pop") == 0){
            if(!QUEUE.empty()){
                cout << QUEUE.front() << "\n";
                QUEUE.pop();
            }
            else cout << "-1\n";
        }
        
        else if(command.compare("size") == 0){
            cout << QUEUE.size() << "\n";
        }
        
        else if(command.compare("empty") == 0){
            QUEUE.empty() ? cout << "1\n" : cout << "0\n";
        }
        
        else if(command.compare("front") == 0){
            if(!QUEUE.empty()) cout << QUEUE.front() << "\n";
            else cout << "-1\n";
        }
        
        else if(command.compare("back") == 0){
            if(!QUEUE.empty()) cout << QUEUE.back() << "\n";
            else cout << "-1\n";
        }
    }
    
    return 0;
}

