// https://www.acmicpc.net/problem/9461
// 파도반 수열
// Written in C++ langs
// 2020. 01. 13.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long DP[101]={0,};

int main() {
    int count;
    int size;
    scanf("%d", &count);
    
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;

    for(int a=0; a<count; a++){
        scanf("%d", &size);
        for(int i=4; i<=size; i++){
            DP[i] = DP[i-2] + DP[i-3];
        }
        cout << DP[size] << endl;
    }
    return 0;
}


