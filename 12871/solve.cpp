// https://www.acmicpc.net/problem/12871
// 무한 문자열
// Written in C++ langs
// 2020. 11. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string a;
    string b;
    
    cin >> a >> b;
    int size = a.size() * b.size();
    
    bool result = true;
    
    int a_idx = 0;
    int b_idx = 0;
    for(int i=0; i<size; i++){
        if(a[a_idx++] != b[b_idx++]){
            result = false;
            break;
        }
    
        if(a_idx == a.size()) a_idx = 0;
        if(b_idx == b.size()) b_idx = 0;
    }
    
    cout << result << "\n";
   
    
    return 0;
}

