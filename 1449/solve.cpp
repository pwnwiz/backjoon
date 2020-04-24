// https://www.acmicpc.net/problem/1449
// 수리공 항승
// Written in C++ langs
// 2020. 04. 02.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> HOLES;
int N, L;
int COUNT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L;
    int loc;
    for(int i=0; i<N; i++){
        cin >> loc;
        HOLES.push_back(loc);
    }
    
    sort(HOLES.begin(), HOLES.end());
    
    int left = HOLES[0];
    COUNT=1;
    
    for(int i=1; i<HOLES.size(); i++){
        if(HOLES[i] - left > L - 1){
            left = HOLES[i];
            COUNT++;
        }
    }
    
    cout << COUNT << "\n";
    
    return 0;

}


