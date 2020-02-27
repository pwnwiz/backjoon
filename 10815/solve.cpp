// https://www.acmicpc.net/problem/10815
// 숫자 카드
// Written in C++ langs
// 2020. 02. 27.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int K;
int CARD[500001]={0,};
bool RESULT[500001]={0,};
int RESULT_CUR=0;
int TMP=0;

bool checkSmaller(int val){
    bool res;
    CARD[val] <= TMP ? res = true : res = false;
    return res;
}

void bisect(int begin, int end){
    if(end - begin <=1){
        if(CARD[begin] == TMP){
            RESULT[RESULT_CUR] = true;
        } else{
            RESULT[RESULT_CUR] = false;
        }
    }
    else{
        int mid = (begin+end)/2;
        
        if(checkSmaller(mid)){
            return bisect(mid, end);
        }
        else{
            return bisect(begin, mid);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K;
    for(int i=0; i<K; i++){
        cin >> CARD[i];
    }
    sort(CARD, CARD+K);
    int count;
    cin >> count;
    for(int i=0; i<count; i++){
        cin >> TMP;
        bisect(0, K);
        RESULT_CUR++;
    }
    
    for(int i=0; i<count; i++){
        cout << RESULT[i] << " ";
    }
    cout << "\n";
    
    return 0;
    
}

