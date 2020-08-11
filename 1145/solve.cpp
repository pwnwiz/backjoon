// https://www.acmicpc.net/problem/1145
// 적어도 대부분의 배수
// Written in C++ langs
// 2020. 08. 11.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int NUM[5];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<5; i++){
        cin >> NUM[i];
    }
    
    int cnt;
    int number = 1;
    while(true){
        cnt = 0;

        for(int i=0; i<5; i++){
            if(number % NUM[i] == 0) cnt++;
        }
        
        if(cnt >= 3){
            cout << number << "\n";
            break;
        }
        
        number++;
    }

    return 0;
    
}

