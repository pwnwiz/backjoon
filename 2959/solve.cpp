// https://www.acmicpc.net/problem/2959
// 거북이
// Written in C++ langs
// 2020. 08. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> FOOTFALL(4);

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    for(int i=0; i<4; i++){
        cin >> FOOTFALL[i];
    }
    
    sort(FOOTFALL.begin(), FOOTFALL.end(), greater<>());

    cout << FOOTFALL[1] * FOOTFALL[3] << "\n";
    
}

