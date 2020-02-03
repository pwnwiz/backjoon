// https://www.acmicpc.net/problem/2747
// 피보나치 수
// Written in C++ langs
// 2020. 02. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int DP[46]={0,};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int no;
    cin >> no;
    
    DP[0]=0;
    DP[1]=1;
    
    for(int i=2; i<=no; i++)
        DP[i] = DP[i-1] + DP[i-2];
    
    cout << DP[no] << "\n";
    
    return 0;
    
}

