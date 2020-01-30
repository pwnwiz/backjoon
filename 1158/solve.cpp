// https://www.acmicpc.net/problem/1158
// 요세푸스 문제
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>

using namespace std;

list<int> LIST;
vector<int> RESULT;

int main(){
    int no, count;
    cin >> no >> count;
    
    for(int i=1; i<=no; i++)
        LIST.push_back(i);
    
    auto cursor = LIST.begin();
    
    while(LIST.size() > 0){
        for(int i=0; i<count-1; i++){
            if(cursor == LIST.end()) cursor = LIST.begin();
            cursor++;
            if(cursor == LIST.end()) cursor = LIST.begin();
        }
        
        RESULT.push_back(*cursor);
        cursor = LIST.erase(cursor);
    }
    
    cout << "<";
    for(int i=0; i<RESULT.size()-1; i++){
        cout << RESULT[i] << ", ";
    }
    cout << RESULT[RESULT.size()-1] <<">\n";
    
    return 0;
    
}

