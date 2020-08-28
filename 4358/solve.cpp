// https://www.acmicpc.net/problem/4358
// 생태학
// Written in C++ langs
// 2020. 08. 28.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<string, int> MAP;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int cnt = 0;
    while(getline(cin,input)){
        MAP[input]++;
        cnt++;
    }
    
    cout.precision(4);
    cout << fixed;
    
    for(auto m : MAP){
        cout << m.first << " " << ((double)m.second/cnt)*100 << "\n";
    }
    
    return 0;
    
}

