// https://www.acmicpc.net/problem/6679
// 싱기한 네자리 숫자
// Written in C++ langs
// 2020. 08. 03.
// Wizley

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Calculate(int origin, int digit){
    int sum = 0;
    while(origin){
        sum += origin % digit;
        origin /= digit;
    }
    
    return sum;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i=1000; i<=9999; i++){
        if(Calculate(i, 10) == Calculate(i, 12) && Calculate(i, 10) == Calculate(i, 16)){
            cout << i << "\n";
        }
    }

    return 0;
}

