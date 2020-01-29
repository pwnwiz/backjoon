// https://www.acmicpc.net/problem/10799
// 쇠막대기
// Written in C++ langs
// 2020. 01. 29.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

stack<char> STACK;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string ps;

    cin >> ps;
    int count=0;
    
    for(int i=0; i<ps.size(); i++){
        if(ps[i] == '(')
            STACK.push(ps[i]);
        else{
            STACK.pop();
            if(ps[i-1] == '(')
                count += STACK.size();
            else
                count ++;
        }
    }
    cout << count << "\n";
    return 0;
}

