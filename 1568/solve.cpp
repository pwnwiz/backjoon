// https://www.acmicpc.net/problem/1568
// 새
// Written in C++ langs
// 2020. 08. 10.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int k = 1;
    int t = 0;
    while(true){
        if(N == 0) break;
        
        else if(N-k <0) k = 1;
        
        N -= k;
        t++;
        k++;
    }
    
    cout << t << "\n";
    
    return 0;
    
}

