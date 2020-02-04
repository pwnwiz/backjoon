// https://www.acmicpc.net/problem/10872
// 팩토리얼
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

    long long res=1;
    for(auto i=1; i<=no; i++){
        res *= i;
    }

    cout << res << "\n";
    return 0;
}

