// https://www.acmicpc.net/problem/2374
// 같은 수로 만들기
// Written in C++ langs
// 2020. 12. 01.
// Wizley

#include <iostream>
#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>
#include <set>

using namespace std;

int N;
int RESULT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    vector<int> v(N);
    
    for(int n=0; n<N; n++){
        cin >> v[n];
    }
    
    stack<int> st;
    st.push(v[0]);
    
    for(int i=1; i<v.size(); i++){
        if(st.top() < v[i]){
            
            while(!st.empty() && st.top() <= v[i]){
                int top = st.top();
                int diff = v[i] - top;
                st.pop();
                
                while(!st.empty() && st.top() <= v[i]){
                    st.pop();
                }
                
                RESULT += diff;
                
            }
            st.push(v[i]);
        } else {
            st.push(v[i]);
        }
    }
 
    if(st.size() > 1){
        int minv = 987654321;
        int maxv = -1;
        
        while(!st.empty()){
            int c = st.top();
            st.pop();
            
            minv = min(minv, c);
            maxv = max(maxv, c);
        }
        RESULT += maxv - minv;
    }
    cout << RESULT << "\n";
    return 0;
}

