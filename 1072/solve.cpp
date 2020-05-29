// https://www.acmicpc.net/problem/1072
// 게임
// Written in C++ langs
// 2020. 05. 29.
// Wizley

#include <iostream>
#include <algorithm>

using namespace std;

long long X, Y;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;
    
    long long init = (Y*100)/X;
    
    if(init >= 99){
        cout << "-1\n";
        return 0;
    }
    
    long long l = 0;
    long long r = 2000000002;
    
    while(l<=r){
        long long mid = (l+r)/2;

        long long now = ((Y+mid)*100)/(X+mid);
        
        if(now > init){
            r = mid-1;
        }
        
        else{
            l = mid+1;
        }
    }
    
    cout << l << "\n";

    return 0;

}

