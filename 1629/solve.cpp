// https://www.acmicpc.net/problem/1629
// 곱셈
// Written in C++ langs
// 2020. 03. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

enum{
    WHITE=0,
    BLUE=1,
};

long long A, B, C;

using namespace std;

long long pow(long long a, long long p){
    if(p == 0) return 1;
    if(p == 1) return a % C;
    if(p % 2 == 1) return (a * pow((a*a)%C, (p-1)/2)) % C;
    return pow((a*a)%C, p/2) % C;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    cout << pow(A,B) << "\n";
    
    return 0;
    
}

