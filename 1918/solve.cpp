// https://www.acmicpc.net/problem/1918
// 후위 표기식
// Written in C++ langs
// 2020. 07. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string exp;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> exp;
    
    stack<char> st;
    
    for(auto word : exp){
        if(word >= 'A' && word <= 'Z'){
            cout << word;
        }
        
        else if(word == '('){
            st.push(word);
        }
        
        else if(word == ')'){
            while(!st.empty() && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
    
        else if(word == '+' || word == '-'){
            while(!st.empty() && st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.push(word);
        }
        
        else if(word == '*' || word == '/'){
            while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                cout << st.top();
                st.pop();
            }
            st.push(word);
        }
            
    }
    
    while(!st.empty()){
        if(st.top() != '(' && st.top() != ')') cout << st.top();
        st.pop();
    }
    cout << "\n";
    
    return 0;
    
}

