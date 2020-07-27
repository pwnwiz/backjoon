// https://www.acmicpc.net/problem/2231
// 분해합
// Written in C++ langs
// 2020. 07. 27.
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
    
    int init = 0;
    for(int i=1; i<=1000000; i++){
        int c = i;

        string str_c = to_string(c);
        
        for(int d=0; d<str_c.size(); d++){
            c += str_c[d] - '0';
        }
        
        if(c == N){
            init = i;
            break;
        }
    }
    
    cout << init << "\n";
    
    return 0;
}

