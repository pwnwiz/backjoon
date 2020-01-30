// https://www.acmicpc.net/problem/11656
// 접미사 배열
// Written in C++ langs
// 2020. 01. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> WORDS;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string word;
    cin >> word;
    
    for(int i=0; i<word.length(); i++){
        WORDS.push_back(word.substr(i, word.length()));
    }
    
    sort(WORDS.begin(), WORDS.end());
    
    for(int i=0; i<WORDS.size(); i++){
        cout << WORDS[i] << "\n";
    }
    
    return 0;
}



