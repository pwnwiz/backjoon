// https://www.acmicpc.net/problem/9465
// 스티커
// Written in C++ langs
// 2020. 01. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int ARRAY[2][100001]={0,};
int DP[2][100001]={0,};

int main() {
    int count;
    int length;
    scanf("%d", &count);
    
    for(int i=0; i<count; i++){
        scanf("%d", &length);
        for(int j=0; j<2; j++){
            for(int k=0; k<length; k++){
                scanf("%d", &ARRAY[j][k]);
            }
        }
    
        DP[0][0] = ARRAY[0][0];
        DP[1][0] = ARRAY[1][0];
        DP[0][1] = ARRAY[1][0] + ARRAY[0][1];
        DP[1][1] = ARRAY[0][0] + ARRAY[1][1];
        
        for(int j=2; j<=length; j++){
            DP[0][j] = ARRAY[0][j] + max(DP[1][j-2], DP[1][j-1]);
            DP[1][j] = ARRAY[1][j] + max(DP[0][j-2], DP[0][j-1]);
        }
        
        printf("%d\n", max(DP[0][length-1], DP[1][length-1]));
    }
}

