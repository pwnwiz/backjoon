// https://www.acmicpc.net/problem/1676
// 팩토리얼 0의 개수
// Written in C++ langs
// 2020. 02. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int no;
    cin >> no;

    int res=0;
    for(int i=1; i<=no; i++){
        if(i%5==0) res++;
        if(i%(5*5)==0) res++;
        if(i%(5*5*5)==0) res++;
    }
    
    cout << res << "\n";
    
    return 0;
}

