// https://www.acmicpc.net/problem/1100
// 하얀 칸
// Written in C++ langs
// 2020. 08. 07.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char MAP[8][8];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin >> MAP[i][j];
        }
    }
    
    int count = 0;
    
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            // 0, 2, 4, 6,
            if(i%2 == 0){
                if(j%2 == 0 && MAP[i][j] == 'F') count++;
            }
            // 1, 3, 5, 7
            else {
                if(j%2 == 1 && MAP[i][j] == 'F') count++;
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
    
}

