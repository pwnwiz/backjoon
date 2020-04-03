// https://www.acmicpc.net/problem/1541
// 잃어버린 괄호
// Written in C++ langs
// 2020. 04. 03.
// Wizley
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string SEN;
stack<int> NUMBERS;
stack<char> EXPRESSIONS;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> SEN;
    
    int number=0;
    for(int i=0; i<SEN.length(); i++){
        if(SEN[i]>='0' && SEN[i]<='9'){
            number = number*10 + SEN[i]-'0';
        }
        
        else{
            NUMBERS.push(number);
            if(SEN[i] == '+'){
                EXPRESSIONS.push('+');
            }
            
            else{
                EXPRESSIONS.push('-');
            }
            number = 0;
        }
    }
    NUMBERS.push(number);
    
    int res = 0;
    while(!EXPRESSIONS.empty()){
        char exp = EXPRESSIONS.top();
        EXPRESSIONS.pop();
        
        int val = NUMBERS.top();
        NUMBERS.pop();
        
        if(exp == '-'){
            res -= val;
        }
        else{
            int val2 = NUMBERS.top();
            NUMBERS.pop();
            NUMBERS.push(val + val2);
        }
    }
    res += NUMBERS.top();
    cout << res << "\n";
    
    return 0;
    
}

