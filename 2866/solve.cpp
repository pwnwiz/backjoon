// https://www.acmicpc.net/problem/2866
// 문자열 잘라내기
// Written in C++ langs
// 2020. 07. 06.
// Wizley

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int RES = 0;
int R, C;
char STR[1000][1000];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;

    set<string> set1;
    
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> STR[i][j];
        }
    }
    
    for(int i=0; i<C; i++){
        string a;
        for(int j=0; j<R; j++){
            a += STR[j][i];
        }
        set1.insert(a);
    }
    
    for(int res=0; res<R-1; res++){
        set<string> set2;
        for(auto str : set1){
            set2.insert(str.substr(1));
        }
        
        if(set2.size() != C){
            cout << RES << "\n";
            return 0;
        }
        
        set1 = set2;
        RES++;
    }
    
    RES = R-1;
    cout << RES << "\n";
    
    return 0;
}

