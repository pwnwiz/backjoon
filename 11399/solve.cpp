// https://www.acmicpc.net/problem/11399
// ATM
// Written in C++ langs
// 2020. 03. 09.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> PEOPLE;
int N;
int TOTAL = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int human;
    for(int i=0; i<N; i++){
        cin >> human;
        PEOPLE.push_back(human);
    }
    
    sort(PEOPLE.begin(), PEOPLE.end());
    
    int result = 0;
    for(int i=0; i<PEOPLE.size(); i++){
        result = result + PEOPLE[i];
        TOTAL += result;
    }
    
    cout << TOTAL << "\n";
    
}

