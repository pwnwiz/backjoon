// https://www.acmicpc.net/problem/9012
// 괄호
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
    
    int count;
    string ps;

    cin >> count;
    for(int i=0; i<count; i++){
        cin >> ps;
        
        for(int i=0; i<ps.size(); i++){
            if((ps.substr(i,1)).compare("(")==0){
                STACK.push(ps[i]);
            }
            else if((ps.substr(i,1)).compare(")")==0){
                if(STACK.empty()){
                    cout << "NO\n";
                    goto LABEL;
                }
                else STACK.pop();
            }
        }
        STACK.empty() ? cout <<"YES\n" : cout <<"NO\n";
        LABEL:
        while(!STACK.empty()) STACK.pop();
    }
    
    return 0;
}

