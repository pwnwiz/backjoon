// https://www.acmicpc.net/problem/11652
// 카드
// Written in C++ langs
// 2020. 01. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

map<long long, int> MAP;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long count, no = 0;
    int max=0;
    cin >> count;
    
    for(long long i=0; i<count; i++){
        cin >> no;
        MAP[no]++;
    }
  
    for(auto i=MAP.begin(); i!=MAP.end(); i++){
        if(i->second > max){
            max = i->second;
            no = i->first;
        }
    }
    cout << no << "\n";
    return 0;
}

