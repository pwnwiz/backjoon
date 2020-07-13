// https://www.acmicpc.net/problem/1874
// 스택 수열
// Written in C++ langs
// 2020. 07. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> s;
    vector<int> v;
    vector<char> res;
    
    cin >> N;
    
    int in;
    for(int i=0; i<N; i++){
        cin >> in;
        v.push_back(in);
    }
    
    
    int cur = 1;
    int v_p = 0;
    while(cur <= N){
        if(cur <= v[v_p]){
            s.push(cur);
            res.push_back('+');
            cur++;
        }
        
        else{
            while(!s.empty()){
                if(v[v_p] == s.top()){
                    s.pop();
                    res.push_back('-');
                    v_p++;
                    break;
                }
                
                else if(v[v_p] < s.top()){
                    s.pop();
                    res.push_back('-');
                }
                
                else {
                    cout << "NO\n";
                    exit(0);
                }
            }
        }
    }
    
    while(!s.empty()){
        if(v[v_p] == s.top()){
            s.pop();
            res.push_back('-');
            v_p++;
        }

        else if(v[v_p] < s.top()){
            s.pop();
            res.push_back('-');
        }

        else {
            cout << "NO\n";
            exit(0);
        }
    }
    
    if(v_p != v.size()){
        cout << "NO\n";
    } else {
        for(auto r : res){
            cout << r << "\n";
        }
    }
    
}

