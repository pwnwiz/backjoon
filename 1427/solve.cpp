// https://www.acmicpc.net/problem/1427
// 소트인사이드
// Written in C++ langs
// 2020. 08. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    sort(N.begin(), N.end(), greater<>());
    
    cout << N << "\n";
    
    return 0;
}

