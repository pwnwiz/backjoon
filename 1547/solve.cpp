// https://www.acmicpc.net/problem/1547
// 공
// Written in C++ langs
// 2020. 05. 11.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

bool BALL[4] ={0,};
int F, T;
int N;

void swap(int a, int b){
    bool tmp = BALL[a];
    BALL[a] = BALL[b];
    BALL[b] = tmp;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    BALL[1] = true;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> F >> T;
        swap(F,T);
    }
    
    for(int i=1; i<=3; i++){
        if(BALL[i]) cout << i << "\n";
    }
    
    return 0;
}

