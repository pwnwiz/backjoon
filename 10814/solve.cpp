// https://www.acmicpc.net/problem/10814
// 나이순 정렬
// Written in C++ langs
// 2020. 01. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<int, string>&i, const pair<int, string>&j){
    return i.first < j.first;
}

vector<pair<int,string>> MATRIX;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    cin >> count;
    MATRIX.resize(count);
    
    for(int i=0; i<count; i++)
        cin >> MATRIX[i].first >> MATRIX[i].second;
    
    stable_sort(MATRIX.begin(), MATRIX.end(), compare);
    
    for(int i=0; i<count; i++)
        cout << MATRIX[i].first << " " << MATRIX[i].second << "\n";

}

