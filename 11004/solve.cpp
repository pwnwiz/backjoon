// https://www.acmicpc.net/problem/11004
// K번째 수
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

vector<int> ARR;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long count, no, idx;
    cin >> count >> idx;
    
    for(int i=0; i<count; i++){
        cin >> no;
        ARR.push_back(no);
    }
    
    nth_element(ARR.begin(), ARR.begin()+idx-1, ARR.end());
    cout << ARR[idx-1] << "\n";
}

