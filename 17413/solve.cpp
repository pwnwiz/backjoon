// https://www.acmicpc.net/problem/17413
// 단어 뒤집기 2
// Written in C++ langs
// 2020. 12. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#include <stack>

using namespace std;

stack<char> STACK;
string S;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    getline(cin, S);
    S += " ";
    for(int i=0; i<S.size(); i++){
        char chr = S[i];
        if(chr == ' '){
            string token;
            while(!STACK.empty()){
                token += STACK.top();
                STACK.pop();
            }
            cout << token << " ";
        }
        else if(chr == '<'){
            string token;
            while(!STACK.empty()){
                token += STACK.top();
                STACK.pop();
            }
            cout << token;
            
            for(int c=i; c<S.size(); c++){
                cout << S[c];
                if(S[c] == '>'){
                    i = c;
                    break;
                }
            }
        }
        else {
            STACK.push(chr);
        }
    }
    cout << "\n";
    
    return 0;
    
}

