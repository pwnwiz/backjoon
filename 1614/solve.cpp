// https://www.acmicpc.net/problem/1614
// 영식이의 손가락
// Written in C++ langs
// 2020. 08. 14.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long M;

long long CNT = 0;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> N >> M;
  
    switch(N){
        case 1:
            // 0, 8, 16, 24, 32, ...
            CNT = M * 8;
            break;
        case 2:
            // 1, 7, 9, 15, 17, ...
            !(M % 2) ? CNT = M * 4 + 1 : CNT = M * 4 + 3;
            break;
        case 3:
            // 2, 6, 10, 14, 18, ...
            CNT = M * 4 + 2;
            break;
        case 4:
            // 3, 5, 11, 13, 19, ..
            !(M % 2) ? CNT = M * 4 + 3 : CNT = M * 4 + 1;
            break;
        case 5:
            // 4, 12, 20, 28, 36, 44, ...
            CNT = M * 8 + 4;
            break;
    }
    
    cout << CNT << "\n";
    
    return 0;
}

