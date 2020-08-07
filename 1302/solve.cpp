// https://www.acmicpc.net/problem/1302
// 베스트셀러
// Written in C++ langs
// 2020. 08. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;

map<string, int> MAP;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    string input;
    for(int i=0; i<N; i++){
        cin >> input;
        
        if(MAP.find(input) != MAP.end()){
            MAP[input] += 1;
        } else {
            MAP[input] = 1;
        }
    }
    
    int cnt = 0;
    string result = "";
    for(auto iter=MAP.begin();iter!=MAP.end();iter++)
    {
        if(cnt <= iter->second){
            if(result.empty()){
                result = iter->first;
                cnt = iter->second;
            }
            else if(cnt < iter->second || (cnt == iter->second && result> iter->first)){
                result = iter->first;
                cnt = iter->second;
            }
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

