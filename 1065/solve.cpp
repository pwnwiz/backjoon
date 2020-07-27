// https://www.acmicpc.net/problem/1065
// 한수
// Written in C++ langs
// 2020. 07. 27.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    int cnt = 0;
    for(int i=1; i<=N; i++){
        string c = to_string(i);
        
        if(c.size() <= 2){
            cnt ++;
        } else {
            int diff = c[1] - c[0];
            int digit = 0;
            for(int j=1; j<=c.size(); j++){
                if(c[j] - c[j-1] ==  diff){
                    digit++;
                }
            }

            if(digit == c.size() - 1){
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
    
}

