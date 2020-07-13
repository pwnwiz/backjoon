// https://www.acmicpc.net/problem/2493
// 탑
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
    
    cin >> N;
    
    stack<pair<int,int>> s;
    vector<int> result;
    
    int input;
    for(int idx=1; idx<=N; idx++){
        cin >> input;
        
        while(!s.empty()){
            if(s.top().second >= input){
                result.push_back(s.top().first);
                break;
            }
            s.pop();
        }
        
        if(s.empty()){
            result.push_back(0);
        }
    
        s.push(make_pair(idx, input));
        
    }
    
    for(auto r : result){
        cout << r << " ";
    }
    cout << "\n";
    
    return 0;
}

