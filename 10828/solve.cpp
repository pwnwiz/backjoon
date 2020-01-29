// https://www.acmicpc.net/problem/10828
// 스택
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

stack<int> STACK;

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
            STACK.push(pushValue);
        }
        
        else if(command.compare("pop") == 0){
            if(STACK.empty())
                cout << "-1\n";
            else{
                cout << STACK.top() << "\n";
                STACK.pop();
            }
        }
        
        else if(command.compare("size") == 0){
            cout << STACK.size() << "\n";
        }
        
        else if(command.compare("empty") == 0){
            STACK.empty() ? cout << "1\n" : cout << "0\n";
        }
        
        else if(command.compare("top") == 0){
            STACK.empty() ? cout << "-1\n" : cout << STACK.top() << "\n";
        }
    }
    return 0;
}


