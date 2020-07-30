// https://www.acmicpc.net/problem/1748
// 수 이어 쓰기 1
// Written in C++ langs
// 2020. 07. 30.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long N;
long long RESULT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    //    if(N>10) RESULT += 9;
    //    if(N>100) RESULT += 9*10*2;
    //    if(N>1000) RESULT += 9*10*10*3;
    //    if(N>10000) RESULT += 9*10*10*10*4;
    //    if(N>100000) RESULT += 9*10*10*10*10*5;
    //    if(N>1000000) RESULT += 9*10*10*10*10*10*6;
    //    if(N>10000000) RESULT += 9*10*10*10*10*10*10*7;
    //    if(N>100000000) RESULT += 9*10*10*10*10*10*10*10*8;
    
    if(N<10){
        RESULT = 1*N;
    }
    
    else {
        int pos = 10;
        int digit = 1;
        while(pos <= N){
            RESULT += 9 * pow(10, digit-1) * digit;
            pos *= 10;
            digit++;
        }

        N -= (long long)pow(10, digit-1);
        RESULT += (N+1)*digit;
    }

    cout << RESULT << "\n";

    return 0;
}


