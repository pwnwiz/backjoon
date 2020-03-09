// https://www.acmicpc.net/problem/1744
// 수 묶기
// Written in C++ langs
// 2020. 03. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> MINUS;
vector<int> PLUS;
vector<int> COMBINED;
int RESULT=0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int no;
    for(int i=0; i<N; i++){
        cin >> no;
        if(no<=0)
            MINUS.push_back(no);
        else
            PLUS.push_back(no);
    }
    
    sort(MINUS.begin(), MINUS.end());
    sort(PLUS.begin(), PLUS.end(), greater<int>());
    
    while(MINUS.size() >= 2){
        COMBINED.push_back(MINUS[0]*MINUS[1]);
        MINUS.erase(MINUS.begin());
        MINUS.erase(MINUS.begin());
    }
    
    while(PLUS.size() >= 2){
        if(PLUS[0] == 1 || PLUS[1] == 1){
            break;
        }
        COMBINED.push_back(PLUS[0]*PLUS[1]);
        PLUS.erase(PLUS.begin());
        PLUS.erase(PLUS.begin());
    }
    
    for(int i=0; i<MINUS.size(); i++){
        RESULT += MINUS[i];
    }
    for(int i=0; i<PLUS.size(); i++){
        RESULT += PLUS[i];
    }
    for(int i=0; i<COMBINED.size(); i++){
        RESULT += COMBINED[i];
    }
    
    cout << RESULT << "\n";
    
    return 0;
    
}

