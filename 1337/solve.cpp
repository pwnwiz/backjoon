// https://www.acmicpc.net/problem/1337
// 올바른 배열
// Written in C++ langs
// 2020. 08. 18.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> arr;
map<int, bool> m;

int RESULT = 5;
int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        
        arr.push_back(input);
        m[input] = true;
    }
    
    for(auto c : arr){
        
        int cnt = 0;
        for(int i=0; i<5; i++){
            if(!m[c+i]) cnt ++;
        }
        
        RESULT = min(RESULT, cnt);
    }
    
    cout << RESULT << "\n";
    
    return 0;
}

