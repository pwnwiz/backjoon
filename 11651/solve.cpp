// https://www.acmicpc.net/problem/11651
// 좌표 정렬하기 2
// Written in C++ langs
// 2020. 01. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool compare(const pair<int, int>&i, const pair<int, int>&j){
    if(i.second == j.second) return i.first < j.first;
    return i.second < j.second;
}

vector<pair<int,int>> MATRIX;
int main(){
    int count;
    int x, y;
    scanf("%d", &count);
    
    for(int i=0; i<count; i++){
        scanf("%d %d", &x, &y);
        MATRIX.push_back(make_pair(x, y));
    }
    
    sort(MATRIX.begin(), MATRIX.end(), compare);
    
    for(int i=0; i<count; i++)
        printf("%d %d\n", MATRIX[i].first, MATRIX[i].second);

}

