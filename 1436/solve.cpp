// https://www.acmicpc.net/problem/1436
// 영화감독 
// Written in C++ langs
// 2020. 03. 24.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
int COUNT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
        
    long long start = 666;
    string six = "666";
    while(COUNT<N){
        string tmp = to_string(start);
        auto found = tmp.find(six);
        if(found != string::npos){
            COUNT++;
        }
        start++;
    }
    
    cout << start-1 << "\n";
}

