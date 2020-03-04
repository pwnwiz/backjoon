// https://www.acmicpc.net/problem/1107
// 리모컨
// Written in C++ langs
// 2020. 03. 04.
// Wizley

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int CUR = 100;
int N;
int M;
bool BAN[10]={0,};
int COUNT = 0;

int getCount(int no){
    int res = 0;
    
    while(no>0){
        int idx = no % 10;
        if(BAN[idx]){
            return 0;
        }
        no /= 10;
        res ++;
    }
    return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    char bt;
    for(int i=0; i<M; i++){
        cin >> bt;
        BAN[bt-'0']= true;
    }

    int res = abs(N - CUR);
    
    for(int i=0; i<=1000000; i++){
        int count = 0;
        
        if(i==0){
            BAN[0] ? count = 0 : count = 1;
        } else {
            count = getCount(i);
        }
        
        if(count>0){
            count += abs(i-N);
            if(res > count){
                res = count;
            }
        }
    }
    cout << res << "\n";
    
    return 0;
    
}

