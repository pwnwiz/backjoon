// https://www.acmicpc.net/problem/2800
// 괄호 제거
// Written in C++ langs
// 2020. 07. 17.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;

set<string> SET;
string input;

int braces[200];
bool used[200];

void backtracking(int pos, string words){
    if(pos == input.size()){
        SET.insert(words);
        return;
    }
    
    if(input[pos] == '('){
        used[pos] = true;
        backtracking(pos+1, words+input[pos]);
        used[pos] = false;
        
        backtracking(pos+1, words);
    } else if(input[pos] == ')'){
        if(used[braces[pos]]){
            backtracking(pos+1, words+input[pos]);
        } else {
            backtracking(pos+1, words);
        }
    } else {
        backtracking(pos+1, words+input[pos]);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> st;
    vector<pair<int,int>> brace;
    
    cin >> input;
    
    for(int i=0; i<input.size(); i++){
        if(input[i] == '('){
            st.push(i);
        }
        
        else if(input[i] == ')'){
            braces[i] = st.top();
            st.pop();
        }
    }
    
    backtracking(0, "");
    
    for(auto e: SET){
        if(e.size() != input.size()) cout << e << "\n";
    }

    return 0;
    
}

