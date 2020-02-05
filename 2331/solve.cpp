// https://www.acmicpc.net/problem/2331
// 반복수열
// Written in C++ langs
// 2020. 02. 05.
// Wizley

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <math.h>

int ARRAY[236197]={0,};
int VISIT[237197]={0,};
int TOTAL=1;

using namespace std;

int findNext(int val, int p){
    int res = 0;
    while(val>0){
        int tmp = val % 10;
        res += pow((double)tmp, (double)p);
        val /= 10;
    }
    return res;
}

void DFS(int d, int p){
    VISIT[d] = TOTAL;
    
    while(true){
        int next = findNext(d, p);
        if(!VISIT[next]){
            TOTAL++;
            DFS(next, p);
        }
        else{
            cout << VISIT[next]-1 << "\n";
            exit(0);
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, p;
    cin >> d >> p;
    
    DFS(d,p);
    
    return 0;
    
}
