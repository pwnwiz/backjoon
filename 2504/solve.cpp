// https://www.acmicpc.net/problem/2504
// 괄호의 값
// Written in C++ langs
// 2020. 05. 25.
// Wizley

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<int> STACK;
string input;

int TOTAL = 0;

void impossible(){
    TOTAL = 0;
    cout << TOTAL << "\n";
    exit(0);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> input;
    int t;
    int tc;
    int cnt;
    
    for(int i=0; i<input.size(); i++){
        char c = input[i];

        switch(c){
            case '(':
                STACK.push(-1);
                break;
            case '[':
                STACK.push(-2);
                break;
            case ')':
                tc = 0;
                t = 0;
                cnt = 0;
                if(STACK.empty()){
                    impossible();
                }
                do{
                    t = STACK.top();
                    STACK.pop();
                    
                    // [ ) 인 경우
                    if(t==-2){
                        impossible();
                    }
                    
                    if(t>0){
                        tc += t;
                    }
                    
                    cnt++;
                    
                } while(!STACK.empty() && t!=-1);
                
                // pop 된 값이 ( 가 아닌 경우
                if(t!=-1){
                    impossible();
                }
                
                if(cnt == 1) STACK.push(2);
                else STACK.push(tc*2);
            
                break;
            case ']':
                tc = 0;
                t = 0;
                cnt = 0;
                if(STACK.empty()){
                    impossible();
                }
                do{
                    t = STACK.top();
                    STACK.pop();
                    
                    // ( ] 인 경우
                    if(t==-1){
                        impossible();
                    }
                    
                    if(t>0){
                        tc += t;
                    }
                    
                    cnt++;
                    
                } while(!STACK.empty() && t!=-2);
                
                if(t!=-2){
                    impossible();
                }
                
                if(cnt == 1) STACK.push(3);
                else STACK.push(tc*3);
                
                break;
            default:
                impossible();
        }
    }
    
    // STACK 남아잇는데 숫자만 남지 않은 경우는 예외처리
    TOTAL = 0;
    while(!STACK.empty()){
        int d = STACK.top();
        STACK.pop();
        
        if(d<0) impossible();
        TOTAL += d;
    }
    
    cout << TOTAL << "\n";
    
    return 0;
    
    
}


