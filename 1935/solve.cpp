// https://www.acmicpc.net/problem/1935
// 후위 표기식2
// Written in C++ langs
// 2020. 07. 15.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
string input;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> input;
    
    stack<double> st;
    vector<int> value;
    
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        value.push_back(in);
    }
    
    for(auto word : input){
        
        if(word>='A' && word<='Z'){
            st.push(value[word-'A']);
        }
        
        else {
            double rhs = st.top();
            st.pop();
            double lhs = st.top();
            st.pop();
        
            if(word == '+'){
                st.push(lhs+rhs);
            }
            
            else if(word == '-'){
                st.push(lhs-rhs);
            }
            
            else if(word == '*'){
                st.push(lhs*rhs);
            }
            
            else if(word == '/'){
                st.push(lhs/rhs);
            }
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << st.top() << "\n";
 
    return 0;
}

