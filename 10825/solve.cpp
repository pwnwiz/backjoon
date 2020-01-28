// https://www.acmicpc.net/problem/10825
// 국영수
// Written in C++ langs
// 2020. 01. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

bool compare(const tuple<string,int,int,int>&i, const tuple<string,int,int,int>&j){
    if(get<1>(i) > get<1>(j)) return true;
    else if(get<1>(i) == get<1>(j)){
        if(get<2>(i) < get<2>(j)) return true;
        else if(get<2>(i) == get<2>(j)){
            if(get<3>(i) > get<3>(j)) return true;
            else if(get<3>(i) == get<3>(j)){
                if(get<0>(i) < get<0>(j)) return true;
            }
        }
    }
    return false;
}

vector<tuple<string,int,int,int>> MATRIX;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int count;
    string name;
    int korean;
    int english;
    int mathematics;
    
    cin >> count;
    
    for(int i=0; i<count; i++){
        cin >> name >> korean >> english >> mathematics;
        MATRIX.push_back(make_tuple(name, korean, english, mathematics));
    }
    
    sort(MATRIX.begin(), MATRIX.end(), compare);
    
    for(int i=0; i<count; i++)
        cout << get<0>(MATRIX[i]) << "\n";
}

