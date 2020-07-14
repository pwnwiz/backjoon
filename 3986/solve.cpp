// https://www.acmicpc.net/problem/3986
// 좋은 단어
// Written in C++ langs
// 2020. 07. 14.
// Wizley

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string exp;

int N;
int R = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    string input;
    for(int i=0; i<N; i++){
        cin >> input;
        
        stack<char> st;
        
        for(auto word: input){
            if(st.empty()){
                st.push(word);
            } else {
                if(st.top() == word){
                    st.pop();
                } else {
                    st.push(word);
                }
            }
        }
        
        if(st.empty()){
            R++;
        }
    }
    
    cout << R << "\n";
    
}

